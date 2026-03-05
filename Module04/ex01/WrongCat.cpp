/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:19:04 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 16:36:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &copy){
		WrongAnimal::operator=(copy);// Chiama assignment della base
	}
	return (*this);
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
// Override di makeSound
void	WrongCat::makeSound() const {
	std::cout << "Cip Cip" << std::endl;
}