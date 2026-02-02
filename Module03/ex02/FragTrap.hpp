/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:51:42 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/02 13:19:59 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
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