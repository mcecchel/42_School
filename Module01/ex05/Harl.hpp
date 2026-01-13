/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:21:51 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/12 14:23:31 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
private:
	void	debug();
	void	info();
	void	warning();
	void	error();

public:
	Harl();
	~Harl();
	// Metodo pubblico che chiama i metodi privati
	void	complain(std::string level);
};

#endif