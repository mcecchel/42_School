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
void	PhoneBook::_displayContactTable() const
{
	// Header della tabella
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	
	// Determina quanti contatti mostrare (max 8)
	int	count;
	if (_ContactCount < 8)
		count = _ContactCount;
	else
		count = 8;

	// Stampa contatti
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << _truncateString(_Contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << _truncateString(_Contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << _truncateString(_Contacts[i].getNickname()) << std::endl;
	}
}
// Display dettagli contatto
void	PhoneBook::_displayContactDetails(int index) const
{
	std::cout << "First Name: " << _Contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _Contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _Contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _Contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _Contacts[index].getDarkestSecret() << std::endl;
}

// Cerca contatto
void	PhoneBook::searchContact() const
{
	std::string input;

	if (_ContactCount == 0)
	{
		std::cout << "PhoneBook is empty. No contacts to display." << std::endl;
		return;
	}
	_displayContactTable();

	std::cout << "Enter index to view details: ";
	std::getline(std::cin, input);
	// Validazione input: deve essere un singolo digit
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Error: Invalid index" << std::endl;
		return;
	}
	int index = input[0] - '0';// Converto char in int

	// Validazione range
	int max_index;
	if (_ContactCount < 8)
		max_index = _ContactCount - 1;
	else
		max_index = 7;
	if (index < 0 || index > max_index)
	{
		std::cout << "Error: Index out of range" << std::endl;
		return;
	}
	_displayContactDetails(index);
}