// Il main deve:
//	-Creare un'istanza di PhoneBook
//	-Entrare in un loop infinito
//	-Leggere comandi: ADD, SEARCH, EXIT
//	-Eseguire l'azione corrispondente
//	-Uscire solo con EXIT
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (1)
	{
        std::cout << "\nEnter command: ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
            break ;
		}
		else if (std::cin.eof())// Gestione EOF (Ctrl+D) perché altrimenti il programma va in loop infinito
		{
			std::cout << "\nEOF detected. Exiting." << std::endl;
			break ;
		}
		else
            std::cout << "Invalid command. Use ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}