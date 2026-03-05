/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:00:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:04:46 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

// Materia concreta di tipo "ice"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& copy);
	~Ice();

	// Crea una copia di se stesso sull'heap
	AMateria* clone() const;
	// Override di use() per sparare un dardo di ghiaccio al target
	void use(ICharacter& target);
};

#endif
