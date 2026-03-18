/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:34:04 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/10 15:06:30 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
// Dato che le classi sono vuote e le funzioni sono libere, tutto va in un unico
// file con il suo header

Base* generate(void)
{
	// Inizializzo generatore di numeri casuali con il tempo attuale
	std::srand(std::time(NULL));
	int rand = std::rand() % 3;// Genero un numero casuale tra 0 e 2

	if (rand == 0)
	{
		std::cout << "Generating A" << std::endl;
		return (new A());// Restituisco istanza di A
	}
	else if (rand == 1)
	{
		std::cout << "Generating B" << std::endl;
		return (new B());// Restituisco istanza di B
	}
	else
	{
		std::cout << "Generating C" << std::endl;
		return (new C());// Restituisco istanza di C
	}
}

// Con puntatore (dynamic_cast restituisce NULL se fallisce)
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identify(ptr): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identify(ptr): B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identify(ptr): C" << std::endl;
	else
		std::cout << "Identify(ptr): unknown" << std::endl;
}

// Con reference (dynamic_cast lancia un'eccezione se fallisce)
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identify(ref): A" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identify(ref): B" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identify(ref): C" << std::endl;
		return ;
	}
	catch (...) {}
	std::cout << "Identify(ref): unknown" << std::endl;
}