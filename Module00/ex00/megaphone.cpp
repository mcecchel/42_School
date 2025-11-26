/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:46 by mcecchel          #+#    #+#             */
/*   Updated: 2025/11/25 18:16:37 by mcecchel         ###   ########.fr       */
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
	if (ac == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * ";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << toupper(av[i][j]);
		}
	}
	std::cout << "" << std::endl;
	return (0);
}
