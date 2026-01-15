/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:04:57 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/15 16:45:59 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_value;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& copy);// Ritorna reference per permettere il concatenamento delle assegnazioni
	~Fixed();

	Fixed(const int value);
	Fixed(const float value);
	
	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Comparison operators
	bool	operator>(const Fixed& var) const;
	bool	operator<(const Fixed& var) const;
	bool	operator>=(const Fixed& var) const;
	bool	operator<=(const Fixed& var) const;
	bool	operator==(const Fixed& var) const;
	bool	operator!=(const Fixed& var) const;
	
	// Arithmetc operators
	Fixed	operator+(const Fixed& var) const;
	Fixed	operator-(const Fixed& var) const;
	Fixed	operator*(const Fixed& var) const;
	Fixed	operator/(const Fixed& var) const;

	// Increment/decrement operators
	Fixed&	operator++(void);// Pre-increment (++a)
	Fixed	operator++(int);// Post-increment (a++)
	Fixed&	operator--(void);// Pre-decrement (--a)
	Fixed	operator--(int);// Post-decrement (a--)

	// Static member functions
	static	Fixed& min(Fixed& a, Fixed& b);
	static	const Fixed& min(const Fixed& a, const Fixed& b);
	static	Fixed& max(Fixed& a, Fixed& b);
	static	const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif