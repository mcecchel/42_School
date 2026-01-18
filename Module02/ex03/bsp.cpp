/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:25:57 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/18 17:10:26 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Funzione helper per formula del determinante
Fixed	abs(Fixed x)
{
	if (x < Fixed(0))
		return (Fixed(0) - x);// Tratto caso negativo
	return (x);
}
Fixed	area(Point const& a, Point const& b, Point const& c)
{
// Formula dell'area con determinante: Area = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2
	Fixed result = (a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY())
	) / Fixed(2);
	return (abs(result));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Se il punto è SUL BORDO o su un VERTICE: Una delle aree sarà 0 -> ritorna false
	// Se il punto è DENTRO il triangolo: area(ABC) = area(PAB) + area(PBC) + area(PCA)
	// Se il punto è FUORI: area(ABC) != somma delle aree

	// Calcolo area del triangolo principale
	Fixed	areaABC = area(a, b, c);
	// Calcolo aree dei 3 sotto-triangoli
	Fixed	areaPAB = area(point, a, b);
	Fixed	areaPBC = area(point, b, c);
	Fixed	areaPCA = area(point, c, a);
	// Se una delle aree è 0, il punto è sul bordo o vertice
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0)) {
		return (false);
	}
	// Check se la somma delle aree è uguale all'area tot
	if (areaABC == areaPAB + areaPBC + areaPCA) {
		return (true);
	}
	return (false);
}