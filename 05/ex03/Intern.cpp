
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:50:25 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/06 17:58:36 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// typedef AForm* (*FormCreator)(std::string const &);
// Definisce un alias di tipo per un puntatore a funzione che:
// - accetta un parametro: const std::string&
// - restituisce: AForm*
// Utilizzato come tipo per i puntatori alle funzioni di creazione dei form

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}
Intern::Intern(const Intern& copy) {
	(void)copy;
	std::cout << "Intern copy constructor called" << std::endl;
}
Intern& Intern::operator=(const Intern& copy) {
	(void)copy;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}
Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

// Funzioni di creazione: una per ogni tipo di form, stesso prototipo cosi' possiamo metterle in un array
// Factory pattern senza if/else: array di struct con nome e funzione di creazione
static AForm* createShrubbery(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}
static AForm* createRobotomy(const std::string& target) {
	return (new RobotomyRequestForm(target));
}
static AForm* createPresidential(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

// Struttura che associa nome del form alla sua funzione creatore
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	// tipo del puntatore a funzione di creazione
	typedef AForm* (*FormCreator)(const std::string&);
	
	struct FormEntry// struct che associa nome a funzione di creazione
	{
		std::string name;
		FormCreator creator;
	};
	// tabella di dispatch x aggiungere i nuovi form senza toccare il codice di makeForm
	const FormEntry forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}
	};
	// numero di form nella tabella
	const int formCount = 3;
	// Scansiona la tabella per trovare il form richiesto
	int i = 0;
	while (i < formCount)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i].creator(target));// Creator = funzione di creazione che restituisce un nuovo form con il target specificato
		}
		i++;
	}
	// In caso di nessun form trovato
	std::cout << "Intern cannot create " << formName << " because it's unknown" << std::endl;
	return (NULL);
}

// NB:typedef AForm* (*FormCreator)(std::string const &) definisce un alias per il tipo "puntatore a funzione che prende una stringa const& e restituisce AForm*". Senza il typedef il codice sarebbe illeggibile. Le funzioni static nel .cpp hanno visibilità limitata al file: non inquinano il namespace globale.