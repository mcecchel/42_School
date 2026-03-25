/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:15:44 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/24 15:39:23 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <stdlib.h>

// Mio main
int	main()
{
	// Costruttore di default (:array vuoto)
	std::cout << "=== Default constructor ===" << std::endl;
	Array<int>	empty;
	std::cout << "size: " << empty.size() << std::endl;

	// Costruttore con n
	std::cout << "\n=== Constructor with n = 5 ===" << std::endl;
	Array<int> intArr(5);
	std::cout << "size: " << intArr.size() << std::endl;
	unsigned int i = 0;
	while (i < intArr.size()) {
		std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;
		i++;
	}
	// Assegnazione valori con static_cast: non obbligatorio ma rende la conversione
	// esplicita ed evita eventuali warning
	i = 0;
	while (i < intArr.size()) {
		intArr[i] = static_cast<int>(i * 10);
		i++;
	}

	// Copy constructor
	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> copy(intArr);
	std::cout << "copy size: " << copy.size() << std::endl;
	i = 0;
	while (i < copy.size()) {
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
		i++;
	}
	// Modifico l'originale -> la copia non deve cambiare
	intArr[0] = 999;
	std::cout << "After modifying intArr[0] = 999:" << std::endl;
	std::cout << "intArr[0] = " << intArr[0] << std::endl;
	std::cout << "copy[0]   = " << copy[0] << " (deve essere 0)" << std::endl;

	// Assignment operator
	std::cout << "\n=== Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = intArr;
	std::cout << "assigned size: " << assigned.size() << std::endl;
	assigned[0] = 42;
	std::cout << "After assigned[0] = 42:" << std::endl;
	std::cout << "intArr[0]   = " << intArr[0] << " (deve essere 999)" << std::endl;
	std::cout << "assigned[0] = " << assigned[0] << " (deve essere 42)" << std::endl;

	// Test con std::string
	std::cout << "\n=== Array<std::string> ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "42";
	i = 0;
	while (i < strArr.size()) {
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
		i++;
	}

	// Test array const e operator[] const
	std::cout << "\n=== const Array<int> ===" << std::endl;
	const Array<int> constArr(intArr);
	std::cout << "constArr[0] = " << constArr[0] << std::endl;

	// Test bounds check che deve lanciare eccezione
	std::cout << "\n=== Out of bounds ===" << std::endl;
	try {
		int x = intArr[100];
		(void)x;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try {
		intArr[5] = 0; // size = 5, indice massimo valido = 4
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Tentativo di accesso su array vuoto
	std::cout << "\n=== Access on empty array ===" << std::endl;
	try {
		int x = empty[0];
		(void)x;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}

// Main da intra
// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;
// 	return 0;
// }