/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:07:24 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/05 18:05:44 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	// --- Test form con grade valido ---
	std::cout << "[ VALID FORM ]" << std::endl;
	try {
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test firma riuscita ---
	std::cout << "[ SUCCESSFUL SIGN ]" << std::endl;
	try {
		Bureaucrat alice("Alice", 30);
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
		alice.signForm(contract); // Alice grade 30 <= 50 richiesto: OK
		std::cout << contract << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test firma fallita: grade troppo basso ---
	std::cout << "[ FAILED SIGN (grade too low) ]" << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		Form topSecret("TopSecret", 10, 5);
		std::cout << topSecret << std::endl;
		bob.signForm(topSecret); // Bob grade 100 > 10 richiesto: FAIL
		std::cout << topSecret << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test form con grade non valido ---
	std::cout << "[ INVALID FORM GRADE ]" << std::endl;
	try {
		Form badForm("BadForm", 0, 50); // grade 0: troppo alto
	}
	catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// --- Test firma doppia: non deve cambiare nulla ---
	std::cout << "[ DOUBLE SIGN ]" << std::endl;
	try {
		Bureaucrat ceo("CEO", 1);
		Form memo("Memo", 5, 3);
		ceo.signForm(memo);
		std::cout << memo << std::endl;
		ceo.signForm(memo); // gia' firmato quindi isSigned resta true
		std::cout << memo << std::endl;
	}
	catch (std::exception& exeption) {
		std::cout << "Exception: " << exeption.what() << std::endl;
	}
	return (0);
}