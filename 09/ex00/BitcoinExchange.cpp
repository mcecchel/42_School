/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:16:56 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/03 19:58:56 by mcecchel         ###   ########.fr       */
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
void BitcoinExchange::loadDatabase(const std::string& csvFile)
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

// // Validazione data (: YYYY-MM-DD con valori plausibili)
bool BitcoinExchange::isValidDate(const std::string& date) const
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
