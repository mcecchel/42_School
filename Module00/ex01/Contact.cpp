#include "Contact.hpp"

// Costruttore: inizializza gli attributi a stringhe vuote
Contact::Contact() :	_FirstName(""), _LastName(""), _Nickname(""),
						_PhoneNumber(""), _DarkestSecret(""){}
// Distruttore
Contact::~Contact() {}
// Funz di setting: assegnano valori agli attributi privati
void Contact::setFirstName(std::string FirstName) {_FirstName = FirstName;}
void Contact::setLastName(std::string LastName) {_LastName = LastName;}
void Contact::setNickname(std::string Nickname) {_Nickname = Nickname;}
void Contact::setPhoneNumber(std::string PhoneNumber) {_PhoneNumber = PhoneNumber;}
void Contact::setDarkestSecret(std::string DarkestSecret) {_DarkestSecret = DarkestSecret;}
// Funz get: restituiscono i valori degli attributi privati
std::string Contact::getFirstName() const{
	return (_FirstName);}
std::string Contact::getLastName() const{
	return (_LastName);}
std::string Contact::getNickname() const{
	return (_Nickname);}
std::string Contact::getPhoneNumber() const{
	return (_PhoneNumber);}
std::string Contact::getDarkestSecret() const{
	return (_DarkestSecret);}