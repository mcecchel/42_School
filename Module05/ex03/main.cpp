/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:18:50 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 18:06:41 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	someRandomIntern;

	std::cout << std::endl;
	// --- Test dal subject: RobotomyRequestForm ---
	std::cout << "[ SUBJECT TEST ]" << std::endl;
	{
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			Bureaucrat engineer("Engineer", 45);
			engineer.signForm(*rrf);
			engineer.executeForm(*rrf);
			delete (rrf);
		}
	}
	std::cout << std::endl;

	// --- Test ShrubberyCreationForm ---
	std::cout << "[ SHRUBBERY VIA INTERN ]" << std::endl;
	{
		AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "garden");
		if (shrubbery)
		{
			Bureaucrat gardener("Gardener", 136);
			gardener.signForm(*shrubbery);
			gardener.executeForm(*shrubbery);
			delete (shrubbery);
		}
	}
	std::cout << std::endl;

	// --- Test PresidentialPardonForm ---
	std::cout << "[ PARDON VIA INTERN ]" << std::endl;
	{
		AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (pardon)
		{
			Bureaucrat president("President", 5);
			president.signForm(*pardon);
			president.executeForm(*pardon);
			delete (pardon);
		}
	}
	std::cout << std::endl;

	// --- Test nome sconosciuto ---
	std::cout << "[ UNKNOWN FORM ]" << std::endl;
	{
		AForm* unknown = someRandomIntern.makeForm("coffee request", "everyone");
		if (!unknown)
			std::cout << "No form created, as expected." << std::endl;
	}
	std::cout << std::endl;

	// --- Test: form non firmato prima di eseguire ---
	std::cout << "[ EXECUTE WITHOUT SIGNING ]" << std::endl;
	{
		AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Wall-E");
		if (robotomy)
		{
			Bureaucrat lazy("Lazy", 45);
			lazy.executeForm(*robotomy); // non firmato: deve fallire
			delete (robotomy);
		}
	}
	return (0);
}