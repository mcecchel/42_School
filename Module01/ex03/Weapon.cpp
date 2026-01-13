/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:33:21 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/13 13:25:22 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Inizializzo costruttore di default
Weapon::Weapon() : _type("Unarmed") {
}
// Inizializzo costruttore con type
Weapon::Weapon(std::string type) : _type(type) {
}
Weapon::~Weapon() {
}
const std::string& Weapon::getType() const {
	return (_type);//ritorna reference alla stringa interna, non permette di modificarla
}
void Weapon::setType(std::string type) {
	_type = type;
}