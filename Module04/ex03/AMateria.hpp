/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:21:49 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:01:25 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;// Forward declaration per evitare dipendenza circolare
class AMateria {
protected:
	std::string type;
public:
	AMateria(std::string const & type);// nb: ogni materia deve avere un tipo
	AMateria(const AMateria& copy);// Non copia il type (è fisso per ogni sottoclasse)
	AMateria& operator=(const AMateria& copy);// Come sopra
	virtual ~AMateria();

	// Restituisce il tipo di materia
	std::string const & getType() const;
	// Pure virtual: deve essere implementato nelle classi concrete
	virtual AMateria* clone() const = 0;
	
	// Virtual quindi comportamento di default vuoto, le sottoclassi lo override
	virtual void use(ICharacter& target);
};

#endif