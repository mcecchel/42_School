/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:42:10 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 16:23:16 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"// incluso per rompere dipendenza circolare

class Form;// forward declaration

class Bureaucrat {
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();

	// Restituisce il nome del burocrate
	std::string	const & getName() const;
	// Restituisce il grado del burocrate
	int			getGrade() const;
	// Incrementa grado: diminuisce numero (piu' potere)
	void		incrementGrade();
	// Decrementa grado: aumenta numero (meno potere)
	void		decrementGrade();
	void		signForm(AForm& form);
	void		executeForm(AForm const & form) const;// nuovo metodo

	// Eccezioni nested
	
	// Messaggio errore per grado troppo alto
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	// Messaggio errore per grado troppo basso
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};
// Overload <<: stampa informazioni del burocrate
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

// NB: throw() finale = exception specification e dice che what() non lancia eccezioni.
// È richiesto per fare override corretto di std::exception::what()
#endif