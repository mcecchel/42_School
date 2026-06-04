/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:16:20 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/07 18:16:55 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange	bitcoin;
	try
	{
		bitcoin.loadDatabase("data.csv");
		bitcoin.processInput(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}