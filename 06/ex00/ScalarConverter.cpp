/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:37:22 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/09 17:14:39 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Funzioni di rilevamento del tipo
// ---------------------------------
// Calcola se la stringa rappresenta un char (es 'a')
static bool	isChar(const std::string& str) {
	// Caso 1: formato 'a' con virgolette (lunghezza 3)
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	// Caso 2: singolo carattere senza virgolette (lunghezza 1 ma non numerico)
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

// Calcola se la stringa rappresenta un pseudo-literal (es nan, +inf, -inf ecc)
static bool	pseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff"
			|| str == "-inf" || str == "-inff");
}

// Calcola se la stringa rappresenta un integer
static bool	isInt(const std::string& str)
{
	size_t i = 0;

	if (str.empty())
		return (false);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == str.length())
		return (false);
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

// Calcola se la stringa rappresenta un float
static bool	isFloat(const std::string& str)
{
	// check se la stringa è vuota o non termina con 'f' di float
	if (str.empty() || str[str.length() - 1] != 'f')
		return (false);
	// rimuove la 'f' finale e controlla se il resto e' un nbr valido
	std::string numberPart = str.substr(0, str.length() - 1);
	bool hasDecimalPoint = false;
	size_t i = 0;

	if (numberPart[i] == '-' || numberPart[i] == '+')
		i++;
	while (i < numberPart.length())
	{
		// deve avere 1 punto decimale per essere un float valido
		if (numberPart[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);// piu' di un punto decimale
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(numberPart[i]))
			return (false);
		i++;
	}
	return (hasDecimalPoint);
}

// Calcola se la stringa rappresenta un double
static bool	isDouble(const std::string& str)
{
	bool hasDecimalPoint = false;
	size_t i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);// piu' di un punto decimale
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (hasDecimalPoint);
}

// Funzioni di stampa
// ----------------------
// Stampa il char convertito
static void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

// Stampa l'int convertito
static void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else if (value < static_cast<double>(std::numeric_limits<int>::min()) ||
			 value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl; 
}

// Stampa il float convertito
static void	printFloat(double value)
{
	float fValue = static_cast<float>(value);

	if (std::isnan(fValue))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(fValue))
	{
		if (fValue > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
		// setprecision(1) per mostrare sempre una cifra decimale, anche se e' zero
		std::cout << "float: " << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
}

// Stampa il double convertito
static void	printDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

// Metodo principale
// ----------------------
void	ScalarConverter::convert(const std::string& literal)
{
	double	value = 0.0;

	if (isChar(literal))
	{
		// Se formato 'a', prendi il carattere in mezzo
		if (literal.length() == 3)
			value = static_cast<double>(literal[1]);
		// Se formato a, prendi il primo (e unico) carattere
		else
			value = static_cast<double>(literal[0]);
	}
	else if (pseudoLiteral(literal))
	{
		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf" || literal == "+inff")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	}
	else if (isInt(literal))
	{
		std::istringstream iss(literal);// Per gestire correttamente nbr grandi che potrebbero causare overflow
		long double tmp;// Per gestire numeri che superano i limiti di int

		iss >> tmp;
		value = static_cast<double>(tmp);
	}
	else if (isFloat(literal))
	{
		std::istringstream iss(literal);
		float tmp;

		iss >> tmp;
		value = static_cast<double>(tmp);
	}
	else if (isDouble(literal))
	{
		std::istringstream iss(literal);
		iss >> value;
	}
	else
	{
		std::cout << "Error: Invalid literal format" << std::endl;
		return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}