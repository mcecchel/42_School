/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:26:53 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 16:45:25 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const Animal& copy) : type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &copy){
		this->type = copy.type;
	}
	return (*this);
}
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

// Member functions
void Animal::makeSound() const {
	std::cout << "* Generic animal sound *" << std::endl;
}
std::string Animal::getType() const {
	return (this->type);
}