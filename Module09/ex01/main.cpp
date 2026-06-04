/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:17:03 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/09 14:50:45 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << av[0] << " \"expression\"" << std::endl;
		return (1);
	}

	RPN	rpn;
	try
	{
		int res = rpn.evaluateExpression(av[1]);
		std::cout << res << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}