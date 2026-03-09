/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:38:38 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 18:19:47 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const & name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "Form [" << name << "] constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& copy)
	: name(copy.name), isSigned(copy.isSigned),
	  gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}
// name, gToSign, gToExecute sono const = non possono essere riassegnati, quindi copio solo isSigned
Form& Form::operator=(const Form& copy) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &copy)
		isSigned = copy.isSigned;
	return (*this);
}

Form::~Form() {
	std::cout << "Form [" << name << "] destructor called" << std::endl;
}

std::string const&	Form::getName() const {
	 return (name); }
bool				Form::isFormSigned() const {
	 return (isSigned); }
int					Form::getGradeToSign() const {
	 return (gradeToSign); }
int					Form::getGradeToExecute() const {
	 return (gradeToExecute); }
	 
void Form::beSigned(const Bureaucrat& b)
{
	// grade piu' basso numericamente = piu' potere
	// il bureaucrat deve avere grade <= gradeToSign
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high, must be >= 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low, must be <= 150");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form [" << form.getName() << "]:" << " signed = ";
	if (form.isFormSigned())
		os << "yes";
	else
		os << "no";
	os << ", grade to sign = " << form.getGradeToSign() << ", grade to execute = " << form.getGradeToExecute();
	return (os);
}