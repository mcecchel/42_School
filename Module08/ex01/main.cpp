/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:57:12 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/26 18:28:48 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	// Test da subject
	std::cout << "=== subject test ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 2
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 14
	}

	// Test con 10.000 numeri (addRange con iteratori)
	std::cout << "\n=== 10.000 nbrs via addRange ===" << std::endl;
	{
		const int N = 10000;
		Span big(N);

		// Genera N numeri casuali in un vettore
		std::srand(std::time(NULL));
		std::vector<int> src;
		src.reserve(N);
		int i = 0;
		while (i < N)
		{
			src.push_back(std::rand() % 1000000);
			i++;
		}
		big.addRange(src.begin(), src.end());
		std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << big.longestSpan()  << std::endl;
	}

	// Test eccezioni
	std::cout << "\n=== Exception test ===" << std::endl;
	{
		// Span pieno
		try {
			Span sp(2);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);// Deve lanciare eccezione
		}
		catch (std::exception& e) {
			std::cout << "Error (full span): " << e.what() << std::endl;
		}
		// Un solo elemento: no span
		try {
			Span sp(5);
			sp.addNumber(42);
			sp.shortestSpan();
		}
		catch (std::exception& e) {
			std::cout << "Error (one element): " << e.what() << std::endl;
		}
		// Zero elementi
		try {
			Span sp(5);
			sp.longestSpan();
		}
		catch (std::exception& e) {
			std::cout << "Error (no elements): " << e.what() << std::endl;
		}
	}
	// Test addRange con array tramite ptr (che sono iteratori)
	{
		std::cout << "\n=== addRange with array ===" << std::endl;
		int arr[] = {50, 20, 80, 10, 60};
		Span sp(5);
		sp.addRange(arr, arr + 5);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 10
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 70
	}
	return (0);
}