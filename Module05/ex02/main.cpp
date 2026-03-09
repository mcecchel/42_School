/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:18:50 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 16:24:34 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	// --- Test ShrubberyCreationForm ---
	std::cout << "[ SHRUBBERY ]" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 136);
		ShrubberyCreationForm shrubbery("home");
		gardener.signForm(shrubbery);
		gardener.executeForm(shrubbery);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test RobotomyRequestForm ---
	std::cout << "[ ROBOTOMY ]" << std::endl;
	try
	{
		Bureaucrat engineer("Engineer", 45);
		RobotomyRequestForm robotomy("Bender");
		engineer.signForm(robotomy);
		engineer.executeForm(robotomy);
		engineer.executeForm(robotomy); // testo due volte per vedere 50%
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test PresidentialPardonForm ---
	std::cout << "[PRESIDENTIAL PARDON ]" << std::endl;
	try
	{
		Bureaucrat president("President", 5);
		PresidentialPardonForm pardon("Arthur Dent");
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test esecuzione senza firma ---
	std::cout << "[ EXECUTE WITHOUT SIGN ]" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		PresidentialPardonForm pardon("Bob's friend");
		bob.executeForm(pardon); // non firmato: deve fallire
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test grade insufficiente per eseguire ---
	std::cout << "[ GRADE TOO LOW TO EXECUTE ]" << std::endl;
	try
	{
		Bureaucrat weak("Weak", 100);
		Bureaucrat strong("Strong", 1);
		RobotomyRequestForm robotomy("Target");
		strong.signForm(robotomy);// firma ok con grade 1
		weak.executeForm(robotomy);// esecuzione ko: grade 100 > 45 richiesto
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}