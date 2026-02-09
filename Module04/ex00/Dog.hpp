/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:46:16 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/05 17:08:00 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	// Orthodox Canonical Form
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	~Dog();

	// Override di makeSound (virtual in Animal)
	void	makeSound() const;
};

#endif