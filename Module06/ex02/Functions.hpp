/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:31:29 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/10 14:49:06 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Classi derivate vuote
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void); // Funzione per generare un'istanza casuale di A, B o C
void identify(Base* p); // Per identificare il tipo di oggetto puntato da p
void identify(Base& p); // Per identificare il tipo di oggetto referenziato da p

#endif