/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:40:26 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/19 18:45:54 by mcecchel         ###   ########.fr       */
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
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void setName(std::string name);// Setter nome (per inizializzare array)
};
Zombie* zombieHorde(int N, std::string name);

#endif