/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:03:17 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/29 16:40:25 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

// NB: imposto le classi come protected piuttosto che private perche'
// Se fossero private:
	// 1) ScavTrap NON potrebbe accedere a _hitPoints
	// 2) Dovremmo usare getter/setter per tutto
	// = Sarebbe meno efficiente

class ClapTrap{
protected://// protected e non private per ereditarietà
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	// Orthodox Canonical Form
	ClapTrap();// Default
	ClapTrap(std::string name);// Costruttore con nome
	ClapTrap(const ClapTrap& copy);// Costruttore di copia
	ClapTrap& operator=(const ClapTrap& copy);// Copy assignment operator
	~ClapTrap();

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
};

#endif