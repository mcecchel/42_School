/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:50:59 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/05 16:04:39 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Costruttore: inizializza burocrate con nome e grado (1-150)
Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}
// Costruttore di copia: clona burocrate esistente
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Copy constructor called" << std::endl;
}
// Operatore di assegnazione: copia solo grade perche' name e' const
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->_grade = copy._grade;// _name = copy._name perche' non si puo' assegnare un const
	}
	return (*this);
}
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat [" << _name << "] destructor called" << std::endl;
}

std::string	const & Bureaucrat::getName() const {
	return (_name);
}
int Bureaucrat::getGrade() const {
	return (_grade);
}
void Bureaucrat::incrementGrade() {
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade() {
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, must be >= 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, must be <= 150");
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}