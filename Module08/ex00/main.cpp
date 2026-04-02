/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:21:26 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/26 15:41:42 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	// Test con vector
	std::cout << "=== Test 1: vector ===" << std::endl;
	{
		std::vector<int> vector;
		vector.push_back(0);
		vector.push_back(1);
		vector.push_back(-1);
		vector.push_back(42);
		vector.push_back(100);
		// Ricerco eventuale elem presente
		try {
			std::cout << "( Valid number )" << std::endl;
			std::vector<int>::iterator it = easyfind(vector, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		// Se non trovato, lancio eccezione
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		// Ricerco elem non presente
		try {
			std::cout << "( Invalid number )" << std::endl;
			std::vector<int>::iterator it = easyfind(vector, 99);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	// Test con list
	std::cout << "\n=== Test 2: list ===" << std::endl;
	{
		std::list<int> list;
		list.push_back(10);
		list.push_back(20);
		list.push_back(30);
		try {
			std::cout << "( Valid number )" << std::endl;
			std::list<int>::iterator it = easyfind(list, 30);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "( Invalid number )" << std::endl;
			std::list<int>::iterator it = easyfind(list, 25);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	// Test con deque
	std::cout << "\n=== Test 3: deque ===" << std::endl;
	{
		std::deque<int> deque;
		deque.push_back(5);
		deque.push_back(10);
		deque.push_back(15);
		try {
			std::cout << "( Valid number )" << std::endl;
			std::deque<int>::iterator it = easyfind(deque, 10);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "( Invalid number )" << std::endl;
			std::deque<int>::iterator it = easyfind(deque, 20);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	// Test con container const
	std::cout << "\n=== Test 4: const container ===" << std::endl;
	{
		std::vector<int> tmp;
		tmp.push_back(1);
		tmp.push_back(2);
		tmp.push_back(3);
		const std::vector<int> constVector(tmp);
		try {
			std::cout << "( Valid number )" << std::endl;
			std::vector<int>::const_iterator it = easyfind(constVector, 2);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		try {
			std::cout << "( Invalid number )" << std::endl;
			std::vector<int>::const_iterator it = easyfind(constVector, 4);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}