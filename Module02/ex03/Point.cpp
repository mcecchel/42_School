/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:25:48 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/18 16:32:42 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
// Essendo x e y const vanno inizializzati con initialization list

Point::Point(): _x(0), _y(0) {
}
Point::Point(const float x, const float y) : _x(x), _y(y) {
}
Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {
}
Point& Point::operator=(const Point& copy) {
	// Dato che _x e _y sono const non posso modificarli = ritorno solo *this
	(void)copy;// Evita warning di unused parameter
	return (*this);
}
Point::~Point() {
}
Fixed Point::getX(void) const {
	return (this->_x);
}
Fixed Point::getY(void) const {
	return (this->_y);
}
