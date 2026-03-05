/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:00:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 17:17:29 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
	int i = 0;

	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character(const Character& copy) : _name(copy._name)
{
	int i = 0;

	while (i < 4)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();// Crea nuova copia
		else
			_inventory[i] = NULL;
		i++;
	}
}

Character& Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		int i = 0;

		while (i < 4) 
		{
			if (_inventory[i])// Se presente, elimina la materia esistente
				delete (_inventory[i]);
			if (copy._inventory[i])// Se presente, clona la nuova materia
				_inventory[i] = copy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
			i++;
		}
	}
	return (*this);
}

Character::~Character()
{
	int i = 0;

	while (i < 4)
	{
		if (_inventory[i])
			delete (_inventory[i]);
		i++;
	}
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return ;

	int i = 0;
	while (i < 4)
	{
		if (!_inventory[i]) {
			_inventory[i] = materia;
			return;
		}
		i++;
	}
	// Se arriva qui l'inventario e' pieno = non facciamo nulla
}

// nb: non elimina la materia, e' responsabilità del chiamante
void Character::unequip(int index) {
	if (index >= 0 && index < 4)
		_inventory[index] = NULL;
}

void Character::use(int index, ICharacter& target) {
	if (index >= 0 && index < 4 && _inventory[index])
		_inventory[index]->use(target);
}
