/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:33:25 by marianna          #+#    #+#             */
/*   Updated: 2026/01/04 15:13:48 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
	std::string _type;

public:
	Weapon();// Constructor di default
	Weapon(std::string type);// Constructor con tipo
	~Weapon();

	//Il metodo getter getType() ritorna const std::string&, quindi
		//const: non si può modificare il tipo attraverso il return
		//&: ritorna reference (non copia), più efficiente
		//il metodo è const: non modifica l'oggetto Weapon
	const	std::string& getType() const;
	void	setType(std::string type);//Setter: modifica type
};

#endif