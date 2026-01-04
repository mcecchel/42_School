/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:34:13 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:32:16 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

// Ha un pointer a Weapon
// Weapon NON nel constructor
// Può essere disarmato (pointer = NULL)
// Creo metodo setWeapon() per armarsi dopo
class HumanB {
private:
	std::string _name;
	Weapon* _weapon;  // è pointer perché può essere disarmato, quindi NULL

public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon& weapon);// Metodo per armarsi dopo
	void	attack() const;
};
#endif