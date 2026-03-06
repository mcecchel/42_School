/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:40:43 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 15:42:34 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

// PresidentialPardonForm esegue una grazia presidenziale su un target specificato
class PresidentialPardonForm : public AForm {
private:
	std::string	target;
public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm();

	// Override del metodo virtuale puro: stampa un messaggio di grazia per il target
	void execute(Bureaucrat const &executor) const;
};

#endif