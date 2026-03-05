/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:56:16 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 15:14:13 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== TEST 1: Creating and deleting animals ===" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	
	std::cout << "\n=== TEST 2: Array of Animals (half Dog, half Cat) ===" << std::endl;
	const int SIZE = 4;
	AAnimal* animals[SIZE];
	
	for (int i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat();
	
	std::cout << "\n--- Making sounds ---" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	
	std::cout << "\n--- Deleting array ---" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete animals[i];
	
	std::cout << "\n=== TEST 3: Deep Copy ===" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I love bones!");
	
	std::cout << "\n--- Copy constructor ---" << std::endl;
	Dog copy(original);
	
	std::cout << "\n--- Verifying deep copy ---" << std::endl;
	std::cout << "Original Brain: " << original.getBrain() << std::endl;
	std::cout << "Copy Brain:     " << copy.getBrain() << std::endl;
	std::cout << "Are different? " << (original.getBrain() != copy.getBrain() ? "YES ✓" : "NO ✗") << std::endl;
	
	std::cout << "\n--- Testing independence ---" << std::endl;
	copy.getBrain()->setIdea(0, "I love cats!");
	std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea:     " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << "Are different? " << (original.getBrain()->getIdea(0) != copy.getBrain()->getIdea(0) ? "YES ✓" : "NO ✗") << std::endl;
	
	std::cout << "\n--- Automatic destruction ---" << std::endl;
	return (0);
}