/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:32:00 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 17:17:14 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Costruttore: inizializza il tipo della materia
AMateria::AMateria(std::string const & type) : type(type) {
}
// Non copia il type perche' e' una caratteristica intrinseca di ogni sottoclasse
AMateria::AMateria(const AMateria& copy) {
	(void)copy;
}
// Come sopra
AMateria& AMateria::operator=(const AMateria& copy) {
	(void)copy;
	return (*this);
}
AMateria::~AMateria() {
}
std::string const & AMateria::getType() const {
	return (this->type);
}
// Comportamento di default vuoto, le sottoclassi (Ice, Cure) faranno override
void AMateria::use(ICharacter& target) {
	(void)target;
}
