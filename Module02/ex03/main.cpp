/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:24:21 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/18 17:06:32 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(5, 10);
	
	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << std::endl;
	
	// Test 1: Punto dentro
	Point inside(5, 5);
	if (bsp(a, b, c, inside)) {
		std::cout << "Point (5, 5) - Inside: YES" << std::endl;
	}
	else {
		std::cout << "Point (5, 5) - Inside: NO" << std::endl;
	}
	// Test 2: Punto fuori
	Point outside(15, 15);
	if (bsp(a, b, c, outside)) {
		std::cout << "Point (15, 15) - Inside: YES" << std::endl;
	}
	else {
		std::cout << "Point (15, 15) - Inside: NO" << std::endl;
	}
	// Test 3: Punto su un vertice
	Point vertex(0, 0);
	if (bsp(a, b, c, vertex)) {
		std::cout << "Point (0, 0) - Inside: YES" << std::endl;
	}
	else {
		std::cout << "Point (0, 0) - Inside: NO" << std::endl;
	}
	// Test 4: Punto sul bordo
	Point edge(5, 0);
	if (bsp(a, b, c, edge)) {
		std::cout << "Point (5, 0) - Inside: YES" << std::endl;
	}
	else {
		std::cout << "Point (5, 0) - Inside: NO" << std::endl;
	}
	// Test 5: Punto appena dentro
	Point barelyInside(5, 1);
	if (bsp(a, b, c, barelyInside)) {
		std::cout << "Point (5, 1) - Inside: YES" << std::endl;
	}
	else {
		std::cout << "Point (5, 1) - Inside: NO" << std::endl;
	}
	// Test 6: Punto appena fuori
	Point barelyOutside(5, -1);
	if (bsp(a, b, c, barelyOutside)) {
		std::cout << "Point (5, -1) - Inside: YES" << std::endl;
	}
	else {
		std::cout << "Point (5, -1) - Inside: NO" << std::endl;
	}
	return (0);
}