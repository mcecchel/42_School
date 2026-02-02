/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:03:30 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 17:05:41 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;;
		_energyPoints = copy._energyPoints;;
		_attackDamage = copy._attackDamage;;
	}
	return (*this);
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}
void	ClapTrap::attack(const std::string& target) {
	// Controlla se può attaccare
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy to attack :(" << std::endl;
		return ;
	}
	// Controlla se e' vivo
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack (ripj)" << std::endl;
		return ;
	}
	// Attacco valido quindi perde 1 energia
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target 
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount) {
	// Riduce HP
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				<< " damage and is destroyed (AHAH noobie)" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				<< " damage duuuh. HP: " << _hitPoints << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	// Controlla se può rigenerare HP
	if (_energyPoints == 0)// Senza energia non può
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair" << std::endl;
		return ;
	}
	if (_hitPoints == 0)// Se e' morto non può
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot repair (ripj)" << std::endl;
		return ;
	}
	// Rigenerazione valida
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " has regained " << amount 
			  << " points! HP: " << _hitPoints << std::endl;
}
std::string ClapTrap::getName() const {
	return (_name);
}
unsigned int ClapTrap::getHitPoints() const {
	return (_hitPoints);
}
unsigned int ClapTrap::getEnergyPoints() const {
	return (_energyPoints);
}
unsigned int ClapTrap::getAttackDamage() const {
	return (_attackDamage);
}