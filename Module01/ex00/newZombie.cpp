/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:14:34 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/13 13:22:41 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creo zombie su heap = lo zombie sopravvive fuori dalla funzione
Zombie*	newZombie(std::string name){
	Zombie*	nuovo = new Zombie(name);
	return (nuovo);
}