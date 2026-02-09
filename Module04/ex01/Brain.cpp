/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:12:10 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 17:50:09 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	// Inizializzo tutte le idee a stringa vuota
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}
Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}
// Deep Copy dell'Array
Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copy) {
		// Copia tutte le 100 idee
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = copy.ideas[i];// Copia elemento per elemento
		}
	}
	return (*this);
}
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return ("");
}
void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
}