/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:10:01 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/20 15:48:54 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Inizializzo i parametri del costruttore di default
Zombie::Zombie() :	_name("Unnamed") {
	std::cout << "Zombie " << _name << " created" << std::endl;
}
// Inizializzo costruttore per i nomi
Zombie::Zombie(std::string name) :	_name(name) {
	std::cout << "Zombie " << _name << " created" << std::endl;
}
// Distruttore aka stampa messaggio per debug
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}
// Metodo announce
void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}