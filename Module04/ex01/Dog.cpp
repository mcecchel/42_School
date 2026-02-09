/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:26:11 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 17:55:17 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->_brain = new Brain();// Alloca Brain su heap
	std::cout << "Dog constructor called" << std::endl;
}
Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	// DEEP COPY: creo nuovo Brain e ne copio il contenuto
	this->_brain = new Brain(*copy._brain);// Uso copy constructor di Brain
}
Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);// Copia parte di Animal
		// DEEP COPY: dealloca vecchio Brain, poi crea nuovo
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}
Dog::~Dog() {
	// Dealloca Brain, poi chiama automaticamente ~Animal()
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

// Metodi
void	Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
Brain	*Dog::getBrain() const {
	return (this->_brain);
}