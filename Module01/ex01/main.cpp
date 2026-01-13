/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:40:11 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/12 12:40:51 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	N = 50;
	std::cout << "Creating horde of " << N << " zombies..." << std::endl;
	Zombie	*horde = zombieHorde(N, "'Anonimous'");
	
	std::cout << "\nMaking zombies announce themselves..." << std::endl;
	int	i = 0;
	while (i < N)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
		i++;
	}
	std::cout << "\nDestroying horde..." << std::endl;
	delete[] horde;
	
	return (0);
}