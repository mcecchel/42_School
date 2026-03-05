/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:26:53 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 15:12:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal& copy) : type(copy.type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &copy){
		this->type = copy.type;
	}
	return (*this);
}
AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

// Member functions
std::string AAnimal::getType() const {
	return (this->type);
}