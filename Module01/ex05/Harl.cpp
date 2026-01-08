/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:22:15 by marianna          #+#    #+#             */
/*   Updated: 2026/01/08 17:08:41 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}
Harl::~Harl() {
}

void    Harl::debug(){
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}
void    Harl::info() {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void    Harl::warning() {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}
void    Harl::error() {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level) {
	// Array di stringhe con i livelli
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	// Array di PUNTATORI A FUNZIONI MEMBRO
	void (Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	// Check a che liv nell'array corrisponde
	int i = 0;
	while (i < 4)
	{
		// chiamo la funz corrispondente con (this->function[i])()
		if (level == levels[i]) {
			(this->*functions[i])(); // equivale a scrivere if (i == 0) {this-> debug}, if (i == 1)...
			return ;
		}
		i++;
	}
	// Se non trova compatibilità, il livello non è valido
	std::cout << "[UNKNOWN]" << std::endl;
	std::cout << "Unknown complaint level: " << level << std::endl;
}