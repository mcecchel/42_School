/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:16:56 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/07 18:18:48 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : database(copy.database) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		database = copy.database;
	}
	return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

// Carica i tassi di cambio dal file CSV nella mappa (variabile database)
void	BitcoinExchange::loadDatabase(const std::string& csvFile)
{
	// Apre il file CSV
	std::ifstream file(csvFile.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open database file");
	}

	std::string	line;
	std::getline(file, line); // Salta l'header 'date,exchange_rate'
	// Legge ogni riga del file CSV
	while (std::getline(file, line))
	{
		if (line.empty()) {
			continue; // Salta righe vuote
		}
		std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue; // Salta righe non valide
		}
		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		float	rate;
		std::istringstream iss(rateStr);
		if (!(iss >> rate)) {
			continue; // Salta righe con tasso di cambio non valido
		}
		database[date] = rate; // Inserisce la data e il tasso di cambio nella mappa
	}
}

// Validazione data (: YYYY-MM-DD con valori plausibili)
bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return (false);
	}
	
	int		year;
	int		month;
	int		day;
	char	dash1;
	char	dash2;
	std::istringstream iss(date);
	
	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
		return (false);
	}
	// iss >> year >> dash1 >> month >> dash2 >> day;
	if (iss.fail()) {
		return (false);
	}
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		return (false);
	}
	return (true);
}

// Validazione valore (: float o int tra 0 e 1000)
bool	BitcoinExchange::isValidValue(const std::string& strVal, float& output) const
{
	std::istringstream	iss(strVal);
	iss >> output;
	if (iss.fail())
		return (false);
	// Controllo che non ci siano caratteri extra dopo il numero
	std::string			extra;
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
	std::map<std::string, float>::const_iterator iterator = database.lower_bound(date);

	if (iterator == database.end() || iterator->first != date)
	{
		// La data esatta non esiste, prendo l'ultima data precedente
		if (iterator == database.begin())
		{
			throw std::runtime_error("Error: No exchange rate available for this date");
			--iterator;
		}
	}
	return (iterator->second);
}

// Elabora il file di input, validando ogni riga e calcolando il valore in Bitcoin
void	BitcoinExchange::processInputFile(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());// Apro file di input
	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open input file");
	}
	std::string	line;
	std::getline(file, line); // Salta l'header 'date | value'
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		// Trova posizione del delimitatore '|'
		std::size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue; // Salta righe non valide
		}
		std::string date = line.substr(0, pipePos);
		std::string valStr = line.substr(pipePos + 1);
		// Rimuovo spazi iniziali e finali
		std::size_t start = valStr.find_first_not_of(" \t");
		if (start != std::string::npos)
			valStr = valStr.substr(start);
		// Valido la data
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad date => " << date << std::endl;
			continue;// Salta righe con data non valida
		}
		// Validazione valore
		float	value;
		if (!isValidValue(valStr, value))
		{
			std::cerr << "Error: bad value => " << valStr << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number => " << value << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large number => " << value << std::endl;
			continue;
		}
		// Cerco il rate e printo il risultato
		try
		{
			float	rate = getRate(date);
			float	res = value * rate;
			std::cout << date << " => " << value << " = " << res << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << " => " << date << std::endl;
		}
	}
}
