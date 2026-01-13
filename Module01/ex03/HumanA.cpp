/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:33:55 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/12 14:22:28 by mcecchel         ###   ########.fr       */
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
