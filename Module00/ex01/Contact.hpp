#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Nickname;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
	public:
	// Constructor e Destructor
	Contact();
	~Contact();
	// Set - funzioni per modificare i dati della classe contact
	void		setFirstName(std::string FirstName);
	void		setLastName(std::string LastName);
	void		setNickname(std::string Nickname);
	void		setPhoneNumber(std::string PhoneNumber);
	void		setDarkestSecret(std::string DarkestSecret);
	// Get - funzioni che leggono dati, const perché non modificano l'oggetto
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
};

#endif