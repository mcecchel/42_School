/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:26:42 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/05 17:08:09 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;
public:
	// Orthodox Canonical Form
	Animal();
	Animal (const Animal& copy);
	Animal& operator= (const Animal& copy);
	virtual ~Animal();

	// Virtual function per polimorfismo
	virtual void	makeSound() const;
	// Getter
	std::string		getType() const;
};

#endif