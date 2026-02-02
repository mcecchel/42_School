/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:37:19 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 13:50:51 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// modifico ScavTrap per usare ereditarietà virtuale (evita che DiamondTrap abbia due copie di ClapTrap)
class ScavTrap : virtual public ClapTrap {
public:
	// Orthodox Canonical Form
	
	// Default constructor
	ScavTrap();
	// Constructor con nome
	ScavTrap(std::string name);
	// Copy constructor
	ScavTrap(const ScavTrap& copy);
	// Copy assignment operator
	ScavTrap& operator=(const ScavTrap& copy);
	// Destructor
	~ScavTrap();

	// Override del metodo attack (per messaggio diverso)
	void	attack(const std::string& target);
	void	guardGate();
};

#endif