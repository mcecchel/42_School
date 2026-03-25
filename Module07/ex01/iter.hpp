/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:21:10 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/18 17:10:34 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

// T: tipo degli elementi dell'array
// F: tipo della funzione da applicare
template <typename T, typename F>
void	iter(T* array, const std::size_t length, F func)
{
	size_t	i = 0;

	while (i < length)
	{
		func(array[i]);
		++i;
	}
}

#endif