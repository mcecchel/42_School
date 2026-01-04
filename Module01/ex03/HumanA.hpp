/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:33:52 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:14:07 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
	std::string _name;
    Weapon& _weapon;// reference perché è sempre armato
public:
    HumanA(std::string name, Weapon& weapon);// Gli passo già weapon nel costruttore
	~HumanA();

	void	attack() const;
};

#endif