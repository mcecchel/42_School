/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:42:59 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 18:19:47 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm '" << target << "' constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), target(copy.target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);// Copia i membri di AForm
		this->target = copy.target;// Copia il membro target
	}
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm '" << target << "' destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	checkExecution(executor);// Verifica firma e grade prima di eseguire
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}