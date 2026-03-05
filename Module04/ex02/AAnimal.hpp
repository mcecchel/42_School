/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:26:42 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 15:12:12 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
	std::string type;
public:
	// Orthodox Canonical Form
	AAnimal();
	AAnimal (const AAnimal& copy);
	AAnimal& operator= (const AAnimal& copy);
	virtual ~AAnimal();

	// Virtual function per polimorfismo
	virtual void	makeSound() const = 0; // Pure virtual function
	// Getter
	std::string		getType() const;
};

#endif