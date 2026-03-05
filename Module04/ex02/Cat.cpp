/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:53:47 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 15:12:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	this->type = "Cat";
	this->_brain = new Brain();// Alloca Brain su heap
	std::cout << "Cat constructor called" << std::endl;
}
Cat::Cat(const Cat& copy) : AAnimal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	// DEEP COPY: creo nuovo Brain e ne copio il contenuto
	this->_brain = new Brain(*copy._brain);// Uso copy constructor di Brain
}
Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);// Copia parte di AAnimal
		// DEEP COPY: dealloca vecchio Brain, poi crea nuovo
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}
Cat::~Cat() {
	// Dealloca Brain, poi chiama automaticamente ~AAnimal()
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

// Metodi
void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
Brain	*Cat::getBrain() const {
	return (this->_brain);
}