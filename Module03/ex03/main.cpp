/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:10:19 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/04 12:09:42 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "[ Creating DiamondTrap ]" << std::endl;
	DiamondTrap diamond("D-01");
	
	std::cout << "\n[ Testing whoAmI() ]" << std::endl;
	diamond.whoAmI();
	
	std::cout << "\n[ Testing attack ]" << std::endl;
	diamond.attack("target");
	
	std::cout << "\n[ Testing special abilities ]" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();
	
	std::cout << "\n[ Destruction ]" << std::endl;
	return (0);
}