/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:10:47 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/10 15:54:03 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "\n[ TEST 1: Base test (polymorphism) ]" << std::endl;
	std::cout << "\n--- Construction chain ---" << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*d = new Dog();
	const Animal	*c = new Cat();
	std::cout << "\n--- Types ---" << std::endl;
	std::cout << "d type: " << d->getType() << std::endl;
	std::cout << "c type: " << c->getType() << std::endl;
	std::cout << "\n--- Sounds ---" << std::endl;
	c->makeSound();// Output cat sound
	d->makeSound();// Output dog sound
	meta->makeSound();// Output: generic animal sound
	std::cout << "\n--- Destruction chain ---" << std::endl;
	delete meta;
	delete d;
	delete c;

	std::cout << "\n\n[ TEST 2: WrongAnimal (NO polymorphism) ]" << std::endl;
	const WrongAnimal* wrongBase = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "\n--- Types ---" << std::endl;
	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
	std::cout << "\n--- Sounds (NO polymorphism) ---" << std::endl;
	wrongBase->makeSound();
	wrongCat->makeSound();// Output: WrongAnimal sound (no WrongCat)
	std::cout << "\n--- Destruction (NO virtual destructor) ---" << std::endl;
	delete wrongBase;
	delete wrongCat;// Only WrongAnimal destructor called
	
	{
		std::cout << "\n\n[ TEST 3: Direct Objects (no pointers) ]" << std::endl;
		Dog dog;
		Cat cat;
		std::cout << "\n--- Sounds (direct objects) ---" << std::endl;
		dog.makeSound();
		cat.makeSound();
		std::cout << "\n--- Destruction (automatic) ---" << std::endl;
	}

	std::cout << "\n\n[ TEST 4: Array of Animals ]" << std::endl;
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	std::cout << "\n--- All animals make sound ---" << std::endl;
	int i = 0;
	while (i < 4)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
		i++;
	}
	std::cout << "\n--- Delete all ---" << std::endl;
	i = 0;
	while (i < 4)
	{
		delete animals[i];
		i++;
	}
	
	std::cout << "\n\n[ TEST 5: Copy Constructor ]" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	std::cout << "\nOriginal: " << originalDog.getType() << std::endl;
	std::cout << "Copy: " << copiedDog.getType() << std::endl;
	std::cout << "\n--- Both make sound ---" << std::endl;
	originalDog.makeSound();
	copiedDog.makeSound();
	std::cout << "\n--- Automatic destruction ---" << std::endl;

	return (0);
}