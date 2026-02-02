/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:03:20 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 15:32:06 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "\n[ TEST 1: Construction and Creation ]" << std::endl;
	ClapTrap clap1("CT-01");
	std::cout << "Initial stats -> HP: " << clap1.getHitPoints() 
			  << " | Energy: " << clap1.getEnergyPoints() 
			  << " | Damage: " << clap1.getAttackDamage() << std::endl;
	
	std::cout << "\n[ TEST 2: Attack function ]" << std::endl;
	clap1.attack("Enemy1");
	clap1.attack("Enemy2");
	std::cout << "After attacks -> Energy remaining: " << clap1.getEnergyPoints() << "/10" << std::endl;
	
	std::cout << "\n[ TEST 3: Take damage ]" << std::endl;
	clap1.takeDamage(3);
	std::cout << "Current HP: " << clap1.getHitPoints() << "/10" << std::endl;
	clap1.takeDamage(5);
	std::cout << "Current HP: " << clap1.getHitPoints() << "/10" << std::endl;
	
	std::cout << "\n[ TEST 4: Be repaired ]" << std::endl;
	clap1.beRepaired(5);
	std::cout << "After repair -> HP: " << clap1.getHitPoints() 
			  << " | Energy: " << clap1.getEnergyPoints() << std::endl;

	std::cout << "\n[ TEST 5: Energy Depletion ]" << std::endl;
	ClapTrap clap2("CT-02");
	std::cout << "Starting with Energy: " << clap2.getEnergyPoints() << std::endl;
	// Consuma tutta l'energia (10 attacchi)
	for (int i = 0; i < 10; i++) {
		clap2.attack("Target");
	}
	std::cout << "\nEnergy depleted: " << clap2.getEnergyPoints() << "/10" << std::endl;
	std::cout << "Attempting actions with no energy:" << std::endl;
	// Prova ad attaccare senza energia
	clap2.attack("Target");// Dovrebbe fallire
	clap2.beRepaired(5);// Dovrebbe fallire

	std::cout << "\n[ TEST 6: Death (0 HP) ]" << std::endl;
	ClapTrap clap3("CT-03");
	clap3.takeDamage(20);  // Danno che supera HP
	std::cout << "Current HP: " << clap3.getHitPoints() << std::endl;
	std::cout << "Attempting actions while dead:" << std::endl;
	// Prova ad agire da morto
	clap3.attack("Target");// Dovrebbe fallire
	clap3.beRepaired(5);// Dovrebbe fallire

	std::cout << "\n[ TEST 7: Copy Constructor ]" << std::endl;
	ClapTrap clap4("CT-04");
	clap4.takeDamage(3);
	std::cout << "Original CT-04 HP: " << clap4.getHitPoints() << std::endl;
	ClapTrap clap5(clap4);  // Copy
	std::cout << "Copied clap5 HP: " << clap5.getHitPoints() << std::endl;

	std::cout << "\n[ TEST 8: Assignment Operator ]" << std::endl;
	ClapTrap clap6("CT-06");
	std::cout << "Before assignment - CT-06 HP: " << clap6.getHitPoints() << std::endl;
	clap6 = clap4;  // Assignment
	std::cout << "After assignment - CT-06 HP: " << clap6.getHitPoints() << std::endl;
	
	std::cout << "\n[ Destruction Chain ]" << std::endl;
	return (0);
}