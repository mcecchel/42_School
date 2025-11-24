/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:46 by mcecchel          #+#    #+#             */
/*   Updated: 2025/11/24 18:42:18 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * ";
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << toupper(av[i][j]);
		}
	std::cout << "" << std::endl;
	return (0);
}
