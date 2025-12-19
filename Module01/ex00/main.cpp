/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:19:06 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/19 18:37:34 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "[Test 1: newZombie]" << std::endl;
	Zombie	*heapZombie = newZombie("Foo");
	heapZombie->announce();
	delete heapZombie;
	std::cout << "[Test 2: randomChump]" << std::endl;
	randomChump("Fii");
	return (0);
}