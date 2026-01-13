/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:40:39 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/12 12:54:36 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() :	_name("Unnamed") {
}
Zombie::Zombie(std::string name) :	_name(name) {
	std::cout << "Zombie " << _name << " created" << std::endl;
}
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}
void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::setName(std::string name) {
	_name = name;
}