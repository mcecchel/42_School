/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:33:14 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 15:42:09 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>// Per rand() e srand()
#include <ctime>// Per time()

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm '" << target << "' constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), target(copy.target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);// Copia i membri di AForm
		this->target = copy.target;// Copia il membro target
	}
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm '" << target << "' destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	checkExecution(executor);// Verifica firma e grade prima di eseguire
	std::cout << "Bzzzz..." << std::endl;
	// Simula il processo di robotomizzazione con successo al 50%
	if (std::rand() % 2 == 0) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	}
	else {
		std::cout << "Robotomy failed on " << target << " :(" << std::endl;
	}
}