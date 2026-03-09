/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:09:49 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 15:20:57 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "AForm '"<< name << "' constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned),
	gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
		std::cout << "AForm copy constructor called" << std::endl;
}
AForm& AForm::operator=(const AForm &copy) {
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->isSigned = copy.isSigned;
		// name, gradeToSign, gradeToExecute sono const e non possono essere assegnati
	}
	return (*this);
}
AForm::~AForm() {
	std::cout << "AForm '"<< name << "' destructor called" << std::endl;
}

std::string const &AForm::getName() const {
	return (name);
}
bool AForm::isFormSigned() const {
	return (isSigned);
}
int AForm::getGradeToSign() const {
	return (gradeToSign);
}
int AForm::getGradeToExecute() const {
	return (gradeToExecute);
}
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}
// metodo protetto: verifica firma e grade prima dell'esecuzione
void AForm::checkExecution(const Bureaucrat &executor) const {
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}
const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm error: Grade too high, must be >= 1");
}
const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm error: Grade too low, must be <= 150");
}
const char* AForm::FormNotSignedException::what() const throw() {
	return ("AForm error: Form not signed");
}
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm [" << form.getName() << "]:" << " signed = ";
	if (form.isFormSigned())
		os << "yes";
	else
		os << "no";
	os << ", grade to sign = " << form.getGradeToSign();
	os << ", grade to execute = " << form.getGradeToExecute();
	return (os);
}