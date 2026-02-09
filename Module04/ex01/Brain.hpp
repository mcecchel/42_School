/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:04:44 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/09 17:08:46 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
	std::string ideas[100];// Array di 100 idee
public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain&copy);
	~Brain();

	// Getter e Setter per le idee
	std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string& idea);
};

#endif