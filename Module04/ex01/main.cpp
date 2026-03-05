/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:56:16 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 14:32:37 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n[ TEST 1: Base test (polymorphism) ]" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	
	std::cout << "\n\n[ TEST 2: Array of Animals ]" << std::endl;	
	const int SIZE = 6;
	Animal* animals[SIZE];
	std::cout << "\n--- Creating array (half Dog, half Cat) ---" << std::endl;
	// First half: Dogs
	for (int i = 0; i < SIZE / 2; i++) {
		std::cout << "\nCreating Dog " << i << ":" << std::endl;
		animals[i] = new Dog();
	}
	// Second half: Cats
	for (int i = SIZE / 2; i < SIZE; i++) {
		std::cout << "\nCreating Cat " << i << ":" << std::endl;
		animals[i] = new Cat();
	}
	std::cout << "\n--- All animals make sound ---" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << "\nAnimal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	std::cout << "\n--- Deleting all animals ---" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << "\nDeleting animal " << i << ":" << std::endl;
		delete animals[i];
	}
	
	std::cout << "\n\n[ TEST 3: Deep Copy - Dog ]" << std::endl;		
	std::cout << "\n--- Creating original dog ---" << std::endl;
	Dog* original = new Dog();
	std::cout << "\n--- Setting ideas in original ---" << std::endl;
	original->getBrain()->setIdea(0, "I love bones");
	original->getBrain()->setIdea(1, "Squirrels are interesting");
	original->getBrain()->setIdea(2, "I want to play");
	std::cout << "\n--- Creating copy (copy constructor) ---" << std::endl;
	Dog* copy = new Dog(*original);
	std::cout << "\n--- Verifying deep copy ---" << std::endl;
	std::cout << "Original Brain address: " << original->getBrain() << std::endl;
	std::cout << "Copy Brain address:     " << copy->getBrain() << std::endl;
	if (original->getBrain() != copy->getBrain()) {
		std::cout << "✓ Deep copy successful! Different Brain objects" << std::endl;
	}
	else {
		std::cout << "✗ Shallow copy :( Same Brain object" << std::endl;
	}
	std::cout << "\n--- Checking ideas copied correctly ---" << std::endl;
	std::cout << "Original idea 0: " << original->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 0:     " << copy->getBrain()->getIdea(0) << std::endl;
	std::cout << "\n--- Modifying copy's ideas ---" << std::endl;
	copy->getBrain()->setIdea(0, "I love cats");
	std::cout << "Original idea 0: " << original->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 0:     " << copy->getBrain()->getIdea(0) << std::endl;
	if (original->getBrain()->getIdea(0) != copy->getBrain()->getIdea(0)) {
		std::cout << "✓ Ideas are independent! True deep copy" << std::endl;
	}
	else {
		std::cout << "✗ Ideas are shared = Shallow copy" << std::endl;
	}
	std::cout << "\n--- Deleting dogs ---" << std::endl;
	delete original;
	delete copy;
	
	std::cout << "\n\n[ TEST 4: Deep Copy - Assignment Operator ]" << std::endl;		
	Cat cat1;
	Cat cat2;
	std::cout << "\n--- Setting ideas in cat1 ---" << std::endl;
	cat1.getBrain()->setIdea(0, "I love fish");
	cat1.getBrain()->setIdea(1, "Nap time is best time");
	std::cout << "\n--- Assignment: cat2 = cat1 ---" << std::endl;
	cat2 = cat1;
	std::cout << "\n--- Verifying deep copy ---" << std::endl;
	std::cout << "Cat1 Brain address: " << cat1.getBrain() << std::endl;
	std::cout << "Cat2 Brain address: " << cat2.getBrain() << std::endl;
	if (cat1.getBrain() != cat2.getBrain()) {
		std::cout << "✓ Deep copy = Different Brain objects" << std::endl;
	}
	else {
		std::cout << "✗ Shallow copy :( Same Brain" << std::endl;
	}
	std::cout << "\n--- Modifying cat2 ---" << std::endl;
	cat2.getBrain()->setIdea(0, "I hate dogs");
	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	if (cat1.getBrain()->getIdea(0) != cat2.getBrain()->getIdea(0)) {
		std::cout << "✓ Independent Brains!" << std::endl;
	}
	else {
		std::cout << "✗ Shared Brain!" << std::endl;
	}
	std::cout << "\n--- Automatic destruction of cat1 and cat2 ---" << std::endl;
	
	return (0);
}