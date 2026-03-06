/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:23:38 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 16:42:37 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm '"<< target << "' constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), target(copy.target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &copy) {
		AForm::operator=(copy); // assegna la parte AForm (isSigned)
		this->target = copy.target;
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm '"<< target << "' destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	checkExecution(executor); // verifica firma e grade nella base
	std::ofstream file((target + "_shrubbery").c_str());// crea file target_shrubbery
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file");
	// Scrive albero ASCII nel file
	file << "        *        " << std::endl;
	file << "       ***       " << std::endl;
	file << "      *****      " << std::endl;
	file << "     *******     " << std::endl;
	file << "    *********    " << std::endl;
	file << "        |        " << std::endl;
	file.close();
	std::cout << "Shrubbery created in file: " << target + "_shrubbery" << std::endl;
}
