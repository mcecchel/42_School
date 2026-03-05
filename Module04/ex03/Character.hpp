/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:00:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:27:05 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	// Spazio inventario per 4 slot per materie, NULL se slot vuoto
	AMateria* _inventory[4];
public:
	// Inizializza nome e inventario vuoto (NULL)
	Character(std::string const & name);
	// Deep copy = non copia solo i puntatori, clona ogni materia
	Character(const Character& copy);
	// Deep copy = prima elimina le vecchie materie, poi clona le nuove
	Character& operator=(const Character& copy);
	// Elimina tutte le materie equipaggiate
	~Character();

	std::string const & getName() const;
	// Equipaggia una materia nel primo slot libero, se l'inventario è pieno, non fa nulla
	void equip(AMateria* m);
	// Rimuove la materia dallo slot index
	void unequip(int idx);
	// Usa la materia nello slot index sul target
	void use(int idx, ICharacter& target);
};

#endif
