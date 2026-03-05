/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:31:01 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/05 17:59:29 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;// forward declaration per evitare inclusione circolare

class Form {
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	// Costruttore: inizializza il form e valida i gradi (1-150)
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form();

	std::string const&	getName() const;
	bool				isFormSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	// Firma il form se il bureaucrat ha grado sufficiente (grade piu' basso numericamente = piu' potere)
	void				beSigned(const Bureaucrat& bureaucrat);

	// Eccezioni: messaggi di errore
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};
// Operatore <<: stampa le info del form
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif