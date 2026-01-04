/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:33:21 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:43:40 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Inizializzo costruttore di default
Weapon::Weapon() : _type("Unarmed") {
}
// Inizializzo costruttore con type
Weapon::Weapon(std::string type) : _type(type) {   
}
// Inizializzo distruttore
Weapon::~Weapon() {
}
const std::string& Weapon::getType() const {
	return (_type);//ritorna reference alla stringa interna, ma non permette di modificarla
}
void Weapon::setType(std::string type) {
	_type = type;
}