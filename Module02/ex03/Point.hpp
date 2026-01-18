/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:25:31 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/18 16:05:05 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	// Coordinate
	Fixed const	_x;
	Fixed const	_y;

public:
	// Orthodox Canonical Form
	
	// Costruttore di default
	Point();
	// Costruttore da float
	Point(const float x, const float y);
	// Copy constructor
	Point(const Point& copy);
	// Copy assignment operator, inutile ma necessario per la OCF
	Point& operator=(const Point& copy);
	// Distruttore
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

#endif