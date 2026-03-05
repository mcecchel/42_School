/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:41:52 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:52:56 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

// Forward declaration per evitare dipendenza circolare
class AMateria;

// ICharacter: Interfaccia pura per i personaggi
class ICharacter
{
	public:
		// Distruttore virtual obbligatorio per polimorfismo
		virtual ~ICharacter() {}
		// Restituisce il nome del personaggio
		virtual std::string const & getName() const = 0;
		// Equipaggia una materia nel primo slot libero (0-3)
		virtual void equip(AMateria* m) = 0;
		// Rimuove la materia dallo slot index MA NON LA ELIMINA
		virtual void unequip(int idx) = 0;
		// Usa la materia nello slot index sul target
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif