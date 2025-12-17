#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact	_Contacts[8];
	int		_ContactCount;
	// helper functions
	std::string	_truncateString(std::string str) const;
	void		_displayContactTable() const;
	void		_displayContactDetails(int index) const;
	public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact() const;// const perché non modificano l'oggetto
};

#endif