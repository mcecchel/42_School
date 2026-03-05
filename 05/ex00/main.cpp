/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:07:24 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/05 15:09:50 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	// --- Test costruzione valida ---
	std::cout << "[ VALID CONSTRUCTION ]" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		alice.decrementGrade();
		alice.decrementGrade();
		std::cout << "After 2 decrements: " << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test grade troppo alto ---
	std::cout << "[ GRADE TOO HIGH ]" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test grade troppo basso ---
	std::cout << "[ GRADE TOO LOW ]" << std::endl;
	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test overflow del grade ---
	std::cout << "[ INCREMENT OVERFLOW ]" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade(); // deve lanciare
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test underflow del grade ---
	std::cout << "[ DECREMENT UNDERFLOW ]" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();// deve lanciare
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	return (0);
}