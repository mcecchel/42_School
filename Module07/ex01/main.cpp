/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:21:01 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/18 17:13:56 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Funzioni di esempio da passare a iter

template <typename T>
void printElement(T const& elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void doubleValue(T& elem)
{
	elem = elem * 2;
}

void printUpper(std::string const& s)
{
	for (std::size_t i = 0; i < s.length(); i++)
		std::cout << static_cast<char>(std::toupper(s[i]));
	std::cout << std::endl;
}

int main(void)
{
	// Test con array di int
	std::cout << "=== int array ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	const std::size_t intLen = 5;
	iter(intArr, intLen, printElement<int>);

	std::cout << "-- after value x2 --" << std::endl;
	iter(intArr, intLen, doubleValue<int>);
	iter(intArr, intLen, printElement<int>);

	// Test con array di float
	std::cout << "\n=== float array ===" << std::endl;
	float floatArr[] = {1.1f, 2.2f, 3.3f};
	const std::size_t floatLen = 3;
	iter(floatArr, floatLen, printElement<float>);

	// Test con array di std::string
	std::cout << "\n=== string array ===" << std::endl;
	std::string strArr[] = {"hello", "world", "42"};
	const std::size_t strLen = 3;
	iter(strArr, strLen, printElement<std::string>);
	iter(strArr, strLen, printUpper);

	// Test con array const
	std::cout << "\n=== const int array ===" << std::endl;
	const int constArr[] = {10, 20, 30};
	const std::size_t constLen = 3;
	iter(constArr, constLen, printElement<int>);

	return (0);
}