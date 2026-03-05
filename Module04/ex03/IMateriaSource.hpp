/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:00:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 16:39:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

class AMateria;

// Interfaccia pura per la sorgente di materie

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	
	// Impara una nuova materia (memorizza un template per crearla dopo)
	virtual void learnMateria(AMateria*) = 0;
	// Crea una materia del tipo specificato (se imparata) o NULL (se tipo sconosciuto)
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
