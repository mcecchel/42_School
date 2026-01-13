/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:33:21 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/12 14:23:22 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// Funzione per sostituire tutte le occorrenze di s1 con s2 in una stringa
std::string replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	// Check per evitare loop infinito
	if (s1.empty())
		return (str);
	// Cerco tutte le occorrenze di s1 in str
	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result.append(str, pos, found - pos);// aggiungo a result la parte di str prima dell'occorrenza di s1
		result += s2;
		pos = found + s1.length();// aggiorno pos per cercare la prossima occorrenza
	}
	result.append(str, pos, str.length() - pos);// aggiungo il resto di str
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	// Apro file in lettura
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (1);
	}
	std::string outputFilename = filename + ".replace";// Creo file di output
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: could not create output file " << outputFilename << std::endl;
		inputFile.close();
		return (1);
	}
	// Leggo il file riga per riga sostituendo s1 con s2
	std::string	line;
	while (std::getline(inputFile, line))
	{
		std::string	replaced = replaceAll(line, s1, s2);
		outputFile << replaced << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}