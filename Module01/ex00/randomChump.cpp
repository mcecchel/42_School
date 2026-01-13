/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:18:58 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/13 13:22:45 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creo zombie su stack (varlocale) = lo zombie muore automaticamente alla fine della funzione
void	randomChump(std::string name){
	Zombie	nome(name);
	nome.announce();
}