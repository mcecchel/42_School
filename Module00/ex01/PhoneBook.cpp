#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() :	_ContactCount(0){}
// Distruttore
PhoneBook::~PhoneBook() {}
void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;
	int			index;

	std::cout << "Enter First name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: First name cannot be empty" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Enter Last name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Last name cannot be empty" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Nickname cannot be empty" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Enter Phone number: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Phone number cannot be empty" << std::endl;
		return;
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter Darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Darkest secret cannot be empty" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);

	// Salvo il contatto in posizione corretta (circolare)
	index = _ContactCount % 8;
	_Contacts[index] = newContact;
	_ContactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}
// Formattazione testi
	// Tronca stringa se > di 10 caratteri
std::string PhoneBook::_truncateString(std::string str) const
{
	if(str.length() > 10)
		return (str.substr(0, 9) + ".");// estrae caratteri dalla posizione 0 per 9 caratteri
	return (str);// Se length() <= 10, restituisce la stringa originale
}
	// Dispaly table
		// Ogni colonna larga esattamente 10 caratteri
		// Testo allineato a destra
		// Pipe '|' come separatore
		// Mostra solo i contatti effettivamente salvati (max 8)
void	PhoneBook::_displayContactTable() const{
	// Header della tabella
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
}