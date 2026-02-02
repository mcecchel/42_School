/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:36:51 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 17:00:35 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "[ TEST 1: Construction Chain ]" << std::endl;
	ScavTrap scav1("ST-01");
	std::cout << "\nStats: HP=" << scav1.getHitPoints() 
			  << " Energy=" << scav1.getEnergyPoints() 
			  << " Damage=" << scav1.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 2: ScavTrap Attack ]" << std::endl;
	scav1.attack("Enemy1");
	scav1.attack("Enemy2");
	std::cout << "Energy left: " << scav1.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 3: Inherited Methods ]" << std::endl;
	scav1.takeDamage(30);
	std::cout << "HP after damage: " << scav1.getHitPoints() << std::endl;
	scav1.beRepaired(20);
	std::cout << "HP after repair: " << scav1.getHitPoints() << std::endl;
	std::cout << "Energy: " << scav1.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 4: Guard Gate (Special) ]" << std::endl;
	scav1.guardGate();
	std::cout << std::endl;
	
	std::cout << "[ TEST 5: Multiple ScavTraps ]" << std::endl;
	ScavTrap scav2("ST-02");
	ScavTrap scav3("ST-03");
	scav2.attack("Target");
	scav3.guardGate();
	std::cout << std::endl;
	std::cout << "[ TEST 6: Copy Constructor ]" << std::endl;
	scav1.takeDamage(20);  // Modifica scav1
	ScavTrap scav4(scav1);  // Copia scav1
	std::cout << "Scav4 HP (copied): " << scav4.getHitPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 7: Comparison with ClapTrap ]" << std::endl;
	ClapTrap clap("CT-01");
	std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
			  << " Energy=" << clap.getEnergyPoints() 
			  << " Damage=" << clap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap stats: HP=" << scav1.getHitPoints() 
			  << " Energy=" << scav1.getEnergyPoints() 
			  << " Damage=" << scav1.getAttackDamage() << std::endl;
	std::cout << "\nClapTrap attack:" << std::endl;
	clap.attack("Target");
	std::cout << "ScavTrap attack:" << std::endl;
	scav1.attack("Target");
	std::cout << std::endl;
	std::cout << "[ Destruction Chain ]" << std::endl;
	return (0);
}