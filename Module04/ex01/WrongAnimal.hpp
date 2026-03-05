/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:04:30 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/05 17:07:47 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;
public:
	// Orthodox Canonical Form
	WrongAnimal();
	WrongAnimal (const WrongAnimal& copy);
	WrongAnimal& operator= (const WrongAnimal& copy);
	~WrongAnimal();

	void		makeSound() const;
	std::string	getType() const;
	// nb: no virtual qui
};

#endif