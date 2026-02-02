/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:37:25 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 12:40:01 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	// Prima chiamo (su) costructor di base, poi modifico i valori per ScavTrap
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);// Chiamo assignment della base
	return (*this);
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}
// Override di Attack: stessa logica di ClapTrap ma messaggi diversi
void	ScavTrap::attack(const std::string& target) {
	// Controlla se può attaccare
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy to attack :(" << std::endl;
		return ;
	}
	// Controlla se e' vivo
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is dead and cannot attack, ripj" << std::endl;
		return ;
	}
	// Attacco valido quindi perde 1 energia
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target 
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}
// Metodo speciale
void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode (cagati)" << std::endl;
}
