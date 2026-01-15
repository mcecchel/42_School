/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:20:59 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/15 16:46:24 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}
Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}
Fixed& Fixed::operator=(const Fixed& copy) {
	if (this != &copy) {
		this->_value = copy.getRawBits();
	}
	return (*this);
}
Fixed::~Fixed() {
}

// Costruttore da int
Fixed::Fixed(const int value) {
	this->_value = value << _fractionalBits;// Converto int a fixed-point shiftando a sinistra
}
// Costruttore da float
Fixed::Fixed(const float value) {
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

// ==============================================
// Comparison operators (>, <, >=, <=, ==, !=)
// ==============================================
bool	Fixed::operator>(const Fixed& var) const {
	return (this->_value > var._value);
}
bool	Fixed::operator<(const Fixed&var) const {
	return (this->_value < var._value);
}
bool	Fixed::operator>=(const Fixed& var) const {
	return (this->_value >= var._value);
}
bool	Fixed::operator<=(const Fixed&var) const {
	return (this->_value <= var._value);
}
bool	Fixed::operator==(const Fixed& var) const {
	return (this->_value == var._value);
}
bool	Fixed::operator!=(const Fixed&var) const {
	return (this->_value != var._value);
}

// ==============================================
// Arithmetc operators (+, -, *, /)
// ==============================================
Fixed Fixed::operator+(const Fixed& var) const
{
	Fixed	res;
	
	res.setRawBits(this->_value + var._value);
	return (res);
}
Fixed Fixed::operator-(const Fixed& var) const
{
	Fixed	res;
	
	res.setRawBits(this->_value - var._value);
	return (res);
}
Fixed Fixed::operator*(const Fixed& var) const
{
	Fixed		res;
	long long	tmp;
	// Moltiplico i raw, poi shift a destra per compensare
	tmp = (long long)this->_value * (long long)var._value;
	res.setRawBits((int)(tmp >> _fractionalBits));
	return (res);
}
Fixed Fixed::operator/(const Fixed& var) const {
	Fixed		res;
	long long	tmp;
	
	// Shift a sinistra il numeratore prima di dividere
	tmp = ((long long)this->_value << _fractionalBits) / var._value;
	res.setRawBits((int)tmp);
	return (res);
}

// ==============================================
// Increment/decrement operators
// ==============================================
// Pre-incremento (++a)
Fixed& Fixed::operator++(void) {
	this->_value++;// Incrementa di 1 raw
	return (*this);// Ritorno la reference
}
// Post-incremento (a++)
Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);// Salvo copia del valore corrente
	this->_value++;
	return (tmp);// Ritorno la copia (valore vecchio)
}
// Pre-decremento (--a)
Fixed& Fixed::operator--(void) {
	this->_value--;
	return (*this);
}
// Post-decremento (a--)
Fixed Fixed::operator--(int) {
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

// ==============================================
// Static member functions
// ==============================================
// Min normale
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}
// Min const
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}
// Max normale
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}
// Max const
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

// ==============================================
// Overload operator<<
// ==============================================
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}