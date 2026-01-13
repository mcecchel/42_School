/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:43:04 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/13 18:30:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_value;// Valore fixed-point
	static const int	_fractionalBits = 8;// Num di bit frazionari
public:
	Fixed();
	Fixed(const Fixed& copy);// Copy constructor
	Fixed& operator=(const Fixed& copy);// Copy assignment operator
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif