/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:50:39 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 16:36:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}
Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy){
		Animal::operator=(copy);// Chiama assignment della base
	}
	return (*this);
}
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}
// Override di makeSound
void	Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}