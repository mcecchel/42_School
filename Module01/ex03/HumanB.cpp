/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:34:19 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:58:23 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Nel costruttore inizializzo weapon a NULL perché all'inizio B è disarmato
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
}
HumanB::~HumanB() {
}
// Setter per arma
void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;  // Salvo l'indirizzo dell'arma
}
void HumanB::attack() const {
	if (_weapon == NULL)
	{
		std::cout << _name << " attacks with bare hands" << std::endl;
	}
	else
	{
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;		
	}
}