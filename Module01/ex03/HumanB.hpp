/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:34:13 by mcecchel          #+#    #+#             */
/*   Updated: 2026/01/13 13:24:34 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
	std::string _name;
	Weapon* _weapon;// è pointer perché può essere disarmato, quindi NULL

public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon& weapon);// Metodo per armarsi dopo
	void	attack() const;
};
#endif