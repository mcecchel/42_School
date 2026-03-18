/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:51 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/10 15:00:17 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>

int	main()
{
	// Test con generate()
	std::cout << "=== RANDOM GENERATE ===" << std::endl;
	Base* obj = generate();// Genera oggetto casuale di tipo A, B o C
	identify(obj);
	identify(*obj);
	delete (obj);
	std::cout << std::endl;

	// Test espliciti per ogni tipo
	std::cout << "=== EXPLICIT TESTS ===" << std::endl;
	Base*	a = new A();
	Base*	b = new B();
	Base*	c = new C();
	
	std::cout << "-- A --" << std::endl;
	identify(a);
	identify(*a);
	std::cout << "-- B --" << std::endl;
	identify(b);
	identify(*b);
	std::cout << "-- C --" << std::endl;
	identify(c);
	identify(*c);
	
	delete (a);
	delete (b);
	delete (c);
	return (0);
}