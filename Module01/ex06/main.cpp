/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:27:42 by marianna          #+#    #+#             */
/*   Updated: 2026/01/08 17:59:31 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Funzione per convertire livello in numero
int getLvlIndex(std::string level) {
	if (level == "DEBUG")
		return (0);
	else if (level == "INFO")
		return (1);
	else if (level == "WARNING")
		return (2);
	else if (level == "ERROR")
		return (3);
	else
		return (-1); // errore, livello sconosciuto
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	
	Harl		harl;
	std::string	level = av[1];
	int			lvlIndex = getLvlIndex(level);

	// Switch con fall-through (:no break così prosegue al caso dopo)
	switch (lvlIndex)
	{
		case 0:// Debug
			harl.complain("DEBUG");
			std::cout << std::endl;
			// fall through
		case 1:// info
			harl.complain("INFO");
			std::cout << std::endl;
			// fall through
		case 2:// Warning
			harl.complain("WARNING");
			std::cout << std::endl;
			// fall through
		case 3:// Error
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}