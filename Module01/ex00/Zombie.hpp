/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:10:44 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/19 18:10:49 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	private:
		std::string	_name;
	public:
		Zombie();// Construttore di default
		Zombie(std::string name);// Construttore con parametro per settare nome zombie
		~Zombie();// Destructor
		void announce(void);
};
// Funzioni globali
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif