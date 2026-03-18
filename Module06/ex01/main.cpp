/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:47:17 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/09 18:02:37 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main()
{
	// Crea un oggetto Data su heap
	Data* original = new Data();
	original->id = 42;
	original->value = 3.14;
	original->name = "Test obj";

	std::cout << "--- ORIGINAL ---" << std::endl;
	std::cout << "Ptr address: " << original << std::endl;
	std::cout << "ID:              " << original->id << std::endl;
	std::cout << "Name:            " << original->name << std::endl;
	std::cout << "Value:           " << original->value << std::endl;

	// Serializzazione del puntatore
	uintptr_t raw = Serializer::serialize(original);
	std::cout << "\nSerialized (uintptr_t) = " << raw << std::endl;

	// Deserializzazione del puntatore
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "\n--- DESERIALIZED ---" << std::endl;
	std::cout << "Ptr address: " << deserialized << std::endl;
	std::cout << "ID:              " << deserialized->id << std::endl;
	std::cout << "Name:            " << deserialized->name << std::endl;
	std::cout << "Value:           " << deserialized->value << std::endl;

	// Verifico che i puntatori siano identici
	std::cout << "\n--- CHECK ---" << std::endl;
	if (original == deserialized)
		std::cout << "Success: original == deserialized" << std::endl;
	else
		std::cout << "Error: original != deserialized" << std::endl;
	delete (original);
	return (0);
}