/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:26:55 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/18 17:09:44 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>// Per roundf

class Fixed {
private:
	int					_value;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	// Ritorna reference per permettere il concatenamento delle assegnazioni
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	// Costruttori da int/float
	Fixed(const int value);
	Fixed(const float value);
	
	// Conversioni da fixed a int/float
	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
// Overload operator<<, permette operazione std::cout << fixed
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif