/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:59:08 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/18 16:13:02 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

// Scambia i valori dei due parametri, non ritorna nulla
template <typename T>
void	swap(T& a, T& b)
{
	T tmp = a;// Salva il valore di a in una variabile temporanea
	a = b;// Assegna il valore di b a a
	b = tmp;// Assegna il valore temporaneo (originale di a) a b
}

// Ritorna il minore; se uguali ritorna il secondo
template <typename T>
T const&	min(T const& a, T const& b)
{
	if (a < b)
		return (a);
	else
		return (b);// se a >= b, ritorna b
}

// Ritorna il maggiore; se uguali ritorna il secondo
template <typename T>
T const&	max(T const& a, T const& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif