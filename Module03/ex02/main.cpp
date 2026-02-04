/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:14:55 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/04 12:04:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "[ TEST 1: Construction Chain ]" << std::endl;
	FragTrap frag1("FT-01[frag1]");
	std::cout << "\nFragTrap stats: HP=" << frag1.getHitPoints() 
			  << " Energy=" << frag1.getEnergyPoints() 
			  << " Damage=" << frag1.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 2: FragTrap Attack ]" << std::endl;
	frag1.attack("Enemy1");  // Usa ClapTrap::attack() ma con danno 30
	frag1.attack("Enemy2");
	std::cout << "Energy left: " << frag1.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 3: High Fives Guys (Special) ]" << std::endl;	
	frag1.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "[ TEST 4: Inherited Methods ]" << std::endl;
	frag1.takeDamage(40);
	std::cout << "HP after damage: " << frag1.getHitPoints() << std::endl;
	frag1.beRepaired(25);
	std::cout << "HP after repair: " << frag1.getHitPoints() << std::endl;
	std::cout << "Energy: " << frag1.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 5: All Three Together ]" << std::endl;
	ClapTrap clap("CT-01[clap]");
	ScavTrap scav("ST-01[scav]");
	FragTrap frag2("FT-02[frag2]");
	std::cout << "\n--- Stats Comparison ---" << std::endl;
	std::cout << "ClapTrap: HP=" << clap.getHitPoints() 
			  << " Energy=" << clap.getEnergyPoints() 
			  << " Damage=" << clap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap: HP=" << scav.getHitPoints() 
			  << " Energy=" << scav.getEnergyPoints() 
			  << " Damage=" << scav.getAttackDamage() << std::endl;
	std::cout << "FragTrap: HP=" << frag2.getHitPoints() 
			  << " Energy=" << frag2.getEnergyPoints() 
			  << " Damage=" << frag2.getAttackDamage() << std::endl;
	std::cout << "\n--- Attack Messages Comparison ---" << std::endl;
	clap.attack("Target");  // ClapTrap message
	scav.attack("Target");  // ScavTrap message (override)
	frag2.attack("Target"); // ClapTrap message (no override)
	std::cout << "\n--- Special Abilities ---" << std::endl;
	scav.guardGate();
	frag2.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "[ TEST 6: Copy Constructor ]" << std::endl;
	frag1.takeDamage(30);
	FragTrap frag3(frag1);  // Copy
	std::cout << "Frag3 HP (copied): " << frag3.getHitPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ TEST 7: Energy Depletion ]" << std::endl;
	FragTrap frag4("FT-04[frag4]");
	std::cout << "Starting energy: " << frag4.getEnergyPoints() << std::endl;
	// Consuma energia
	for (int i = 0; i < 50; i++) {
		frag4.attack("Dummy");
	}
	std::cout << "Energy after 50 attacks: " << frag4.getEnergyPoints() << std::endl;
	// Prova ad attaccare ancora
	for (int i = 0; i < 55; i++) {
		frag4.beRepaired(1);
	}
	std::cout << "Energy after 55 repairs: " << frag4.getEnergyPoints() << std::endl;
	// Dovrebbe fallire (no energia)
	frag4.attack("Enemy");
	frag4.highFivesGuys();// Questo funziona perche' non costa energia
	std::cout << std::endl;
	
	std::cout << "[ Destruction Chain ]" << std::endl;
	std::cout << "NOTE: Two 'FT-01[frag1]' appear because frag3 is a copy of frag1" << std::endl;
	std::cout << "  - copy constructor copies '_name' too" << std::endl;
	std::cout << "NOTE: For each derived class, you'll see TWO destructors:" << std::endl;
	std::cout << "  - 1) Derived class destructor (FragTrap/ScavTrap)" << std::endl;
	std::cout << "  - 2) Base class destructor (ClapTrap) - automatic\n" << std::endl;
	return (0);
}