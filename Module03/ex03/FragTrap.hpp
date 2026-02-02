/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:51:42 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 13:50:47 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

// modifico FragTrap per usare ereditarietà virtuale (evita che DiamondTrap abbia due copie di ClapTrap)
class FragTrap : virtual public ClapTrap {
public:
	// Default constructor
	FragTrap();
	// Constructor con nome
	FragTrap(std::string name);
	// Copy constructor
	FragTrap(const FragTrap& copy);
	// Copy assignment operator
	FragTrap& operator=(const FragTrap& copy);
	// Destructor
	~FragTrap();

	// Metodo speciale
	void highFivesGuys(void);
};

#endif