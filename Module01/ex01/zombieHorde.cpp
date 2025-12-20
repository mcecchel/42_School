/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:41:00 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/20 16:08:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Alloca n zombie in una singola allocazione heap
Zombie* zombieHorde(int N, std::string name) {
	// Viene chiamato il constructor di default per ogni zombie
	Zombie* horde = new Zombie[N];
	// Inizializza ogni zombie con il nome dato
	int	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}