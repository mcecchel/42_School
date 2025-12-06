#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact	_Contacts[8];// Array statico di 8 contatti
	int		_ContactCount;// Numero totale di contatti aggiunti (che servira'a sostituire i contatti se > 8)
	// helper functions
	std::string	_truncateString(std::string str) const;//  tronca stringhe a 10 caratteri (helper per display)
	void		_displayContactTable() const;// stampa tabella formattata
	void		_displayContactDetails(int index) const;// mostra dettagli di un contatto specifico
	public:
	// Constructor e Destructor
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact() const;// const perché non modificano l'oggetto
};

#endif