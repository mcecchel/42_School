/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:36:39 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/15 13:04:49 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->_value = copy.getRawBits();
	}
	return (*this);
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
// Costruttore da int
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits;// Converto int a fixed-point shiftando a sinistra
}
// Costruttore da float
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	// roundf() arrotonda un float al numero intero piu' vicino, ma restituisce comunque FLOAT
	this->_value = roundf(value * (1 << _fractionalBits));
}
// Conversione a INT
int		Fixed::toInt(void) const {
	// Converte fixed-point a int shiftando a destra
	return (this->_value >> _fractionalBits);
}
// Conversione a FLOAT
float	Fixed::toFloat(void) const {
	// Converte fixed-point a float dividendo per 2^fractionalBits
	return (float)this->_value / (1 << _fractionalBits);
}
int		Fixed::getRawBits(void) const {
	return (this->_value);
}
void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
// Overload operator<<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}