/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:32:20 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:56:51 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		std::cout << "[Test 1: basic]" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "" << std::endl;
	{
		std::cout << "[Test 2: HumanB armed]" << std::endl;
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "" << std::endl;
	{
		std::cout << "[Test 3: HumanB unarmed]" << std::endl;
		HumanB dwight("Dwight");
		dwight.attack();
	}
	return (0);
}