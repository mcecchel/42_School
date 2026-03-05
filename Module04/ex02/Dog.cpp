/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:26:11 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 15:12:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	this->type = "Dog";
	this->_brain = new Brain();// Alloca Brain su heap
	std::cout << "Dog constructor called" << std::endl;
}
Dog::Dog(const Dog& copy) : AAnimal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	// DEEP COPY: creo nuovo Brain e ne copio il contenuto
	this->_brain = new Brain(*copy._brain);// Uso copy constructor di Brain
}
Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);// Copia parte di AAnimal
		// DEEP COPY: dealloca vecchio Brain, poi crea nuovo
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}
Dog::~Dog() {
	// Dealloca Brain, poi chiama automaticamente ~AAnimal()
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