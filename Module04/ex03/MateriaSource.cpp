/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:00:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:51:26 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int i = 0;

	while (i < 4)
	{
		_templates[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	int i = 0;
	while (i < 4)
	{
		if (copy._templates[i])
			_templates[i] = copy._templates[i]->clone();
		else
			_templates[i] = NULL;
		i++;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	if (this != &copy)
	{
		int i = 0;

		while (i < 4) 
		{
			// Elimina il vecchio template
			if (_templates[i])
				delete _templates[i];
			// Clona il nuovo template
			if (copy._templates[i])
				_templates[i] = copy._templates[i]->clone();
			else
				_templates[i] = NULL;
			i++;
		}
	}
	return (*this);
}

// Elimina tutti i template memorizzati
MateriaSource::~MateriaSource()
{
	int i = 0;

	while (i < 4)
	{
		if (_templates[i])
			delete _templates[i];
		i++;
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;
	int i = 0;
	// Cerca il primo slot libero
	while (i < 4)
	{
		if (!_templates[i]) {
			_templates[i] = materia; // Memorizza il puntatore
			return ;
		}
		i++;
	}
	// Se arrivo qui, l'array è pieno = non fo nulla
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (i < 4)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());// Crea una copia del template
		i++;
	}
	return (NULL);// Tipo sconosciuto
}
