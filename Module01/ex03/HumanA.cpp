/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:33:55 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:58:29 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Inizializzo reference prima di eseguire il corpo del costruttore
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}
HumanA::~HumanA() {
}
void HumanA::attack() const {
	std::cout << _name << " attacks with " << _weapon.getType() << std::endl;
}
