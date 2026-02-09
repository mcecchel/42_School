/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:50:39 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 16:36:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}
Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy){
		Animal::operator=(copy);// Chiama assignment della base
	}
	return (*this);
}
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}
// Override di makeSound
void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}