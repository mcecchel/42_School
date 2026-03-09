/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:01:36 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 15:18:02 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;// Forward declaration

class AForm {
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();

	std::string const &getName() const;
	bool isFormSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	// Firma il form se il bureaucrat ha grado sufficiente
	void beSigned(const Bureaucrat &bureaucrat);
	// Metodo virtuale puro = ogni Form concreto lo implementa
	virtual void execute(Bureaucrat const &executor) const = 0;
protected:
	// metodo di verifica condiviso = chiamato dalle classi concrete (verifica firma e grade prima dell'esecuzione)
	void checkExecution(const Bureaucrat &executor) const;
public:
	// Eccezioni: messaggi di errore
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};
};
// Operatore <<: stampa le info del form
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif