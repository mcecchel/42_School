/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:00:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:44:58 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

//Implementazione concreta dell'interfaccia IMateriaSource
class MateriaSource : public IMateriaSource {
private:
	AMateria* _templates[4];
public:
	// Costruttore inizializza tutti i template a NULL
	MateriaSource();
	// Fa deep copy dei template
	MateriaSource(const MateriaSource& copy);
	// Come sopra
	MateriaSource& operator=(const MateriaSource& copy);
	~MateriaSource();

	// Memorizza un prototipo di materia
	void learnMateria(AMateria* m);
	// Clona il prototipo corrispondente al tipo richiesto
	AMateria* createMateria(std::string const & type);
};

#endif
