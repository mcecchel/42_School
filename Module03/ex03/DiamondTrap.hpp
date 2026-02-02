/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:49:11 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 14:00:44 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	// Default constructor
	DiamondTrap();
	// Constructor con nome
	DiamondTrap(std::string name);
	// Copy constructor
	DiamondTrap(const DiamondTrap& copy);
	// Copy assignment operator
	DiamondTrap& operator=(const DiamondTrap& copy);
	// Destructor
	~DiamondTrap();

	// Metodo speciale
	void	whoAmI();
	// Risolve il problema del diamante specificando esplicitamente quale metodo d'attacco usare
	using ScavTrap::attack;
};

#endif