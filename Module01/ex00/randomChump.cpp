/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:18:58 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/19 18:22:54 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Crea zombie su stack (variabile locale)
// Chiama announce()
void	randomChump(std::string name){
	Zombie	nome(name);
	nome.announce();
}
// Lo zombie muore automaticamente alla fine della funzione