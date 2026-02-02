/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:01:54 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 14:08:59 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Trucco per evitare il diamante: inizializzare esplicitamente ClapTrap
DiamondTrap::DiamondTrap() : ClapTrap("default_CT_name") {
	this-> _name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "CT_name") {
	this-> _name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);// Chiamo assignment della base
	return (*this);
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}