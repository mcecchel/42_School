/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:41:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/12 12:55:41 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Alloco n zombie in una singola allocazione heap
Zombie* zombieHorde(int N, std::string name) {
	// Chiamo costruttore di default per ogni zombie
	Zombie* horde = new Zombie[N];
	// Inizializzo ogni zombie con il nome dato
	int	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}