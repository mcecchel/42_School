/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:16:56 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/09 14:30:00 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

namespace
{
	bool	isLeapYear(int year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

	int	getDaysInMonth(int year, int month)
	{
		static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && isLeapYear(year))
			return (29);
		return (days[month - 1]);
	}
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _db(copy._db) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy)
		_db = copy._db;
	return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

// Carica i tassi di cambio dal file CSV nella mappa (variabile database)
void	BitcoinExchange::loadDatabase(const std::string& csvFile)
{
	// Apre il file CSV
	std::ifstream file(csvFile.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open database file.");
	}

	std::string	line;
	std::getline(file, line);// Salta l'header 'date,exchange_rate'
	// Legge ogni riga del file CSV
	while (std::getline(file, line))
	{
		if (line.empty()) {
			continue;// Salta righe vuote
		}
		std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue;// Salta righe non valide
		}
		std::string date = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1);
	
		std::istringstream iss(value);
		float	rate;
		if (!(iss >> rate)) {
			continue;// Salta righe con tasso di cambio non valido
		}
		_db[date] = rate;// Inserisce la data e il tasso di cambio nella mappa
	}
}

// Validazione data (: YYYY-MM-DD con valori plausibili)
bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::istringstream iss(date);
	int		year, month, day;
	char	dash1, dash2;
	iss >> year >> dash1 >> month >> dash2 >> day;
	if (iss.fail() || dash1 != '-' || dash2 != '-')
		return (false);
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return (false);
	if (day > getDaysInMonth(year, month))
		return (false);
	std::string extra;
	if (iss >> extra)
		return (false);
	return (true);
}

// Validazione valore (: float o int tra 0 e 1000)
bool	BitcoinExchange::isValidValue(const std::string& valStr, float& output) const
{
	std::istringstream iss(valStr);
	iss >> output;
	if (iss.fail())
		return (false);
	// Controllo che non ci siano caratteri extra dopo il numero
	std::string extra;
	iss >> extra;
	if (!extra.empty())
		return (false);
	if (output < 0 || output > 1000)
		return (false);
	return (true);
}

// Cerca la data <= date nel map e restituisce il rate
float	BitcoinExchange::getRate(const std::string& date) const
{
	// lower_bound = primo elem con chiave >= date
	std::map<std::string, float>::const_iterator iterator = _db.lower_bound(date);

	if (iterator == _db.end() || iterator->first != date)
	{
		// La data esatta non esiste, prendo l'ultima data precedente
		if (iterator == _db.begin())
			throw std::runtime_error("Error: No exchange rate available for this date");
		--iterator;
	}
	return (iterator->second);
}

// Elabora il file di input, validando ogni riga e calcolando il valore in Bitcoin
void BitcoinExchange::processInput(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);// Salta l'header 'date | value'

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		// Trova il separatore " | "
		std::size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date	= line.substr(0, pipePos);
		std::string valStr	= line.substr(pipePos + 3);
		// Rimuovo spazi iniziali e finali da valStr
		std::size_t start = valStr.find_first_not_of(" \t");
		std::size_t end = valStr.find_last_not_of(" \t");
		if (start != std::string::npos)
			valStr = valStr.substr(start, end - start + 1);
		else
			valStr.clear();
		// Validazione data
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (valStr.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (valStr[0] == '-')
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		std::istringstream iss(valStr);
		double value;
		char extra;
		if (!(iss >> value) || (iss >> extra))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		// Calcolo e stampo il valore in Bitcoin
		try
		{
			float rate   = getRate(date);
			float res = static_cast<float>(value * rate);
			std::cout << date << " => " << value << " = " << res << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}