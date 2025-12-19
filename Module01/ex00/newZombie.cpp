/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:14:34 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/19 18:20:07 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Crea zombie su heap (new)
// Ritorna puntatore
// Lo zombie sopravvive fuori dalla funzione
Zombie*	newZombie(std::string name){
	Zombie*	nuovo = new Zombie(name);
	return (nuovo);
}
// Da fare il delete