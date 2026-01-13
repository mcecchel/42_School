/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:43:14 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/13 18:33:22 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// inizializzo a 0 costruttore di default con initialization list
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
// Copy assignment operator che assegna valore da 'copy' a 'this'
Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {// previene autoassegnazione (problemi se faccio tipo a = a)
		this->_value = copy.getRawBits();
	}
	return (*this);// Ritorna reference per permettere concatenazione (a = b = c)
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
// Getter per ritornare il val di raw
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
// Setter per impostare il val di raw
void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
