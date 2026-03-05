/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:16:59 by mcecchel          #+#    #+#             */
/*   Updated: 2026/02/27 17:16:19 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== TEST 1: Subject Test ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << "[MateriaSource] Learning 2 materias..." << std::endl;
		src->learnMateria(new Ice());
		std::cout << "  -> Learned: Ice (template #1)" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "  -> Learned: Cure (template #2)" << std::endl;
		
		ICharacter* me = new Character("me");
		std::cout << "\n[Character 'me'] Inventory: [empty] [empty] [empty] [empty]" << std::endl;
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		std::cout << "[MateriaSource] Created Ice materia" << std::endl;
		me->equip(tmp);
		std::cout << "  -> Equipped in slot 0. Inventory: [ice] [empty] [empty] [empty]" << std::endl;
		
		tmp = src->createMateria("cure");
		std::cout << "[MateriaSource] Created Cure materia" << std::endl;
		me->equip(tmp);
		std::cout << "  -> Equipped in slot 1. Inventory: [ice] [cure] [empty] [empty]" << std::endl;
		
		ICharacter* bob = new Character("bob");
		std::cout << "\n[Actions] 'me' uses materias on 'bob':" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		
		std::cout << "\n[Cleanup] Deleting all objects..." << std::endl;
		delete (bob);
		delete (me);
		delete (src);
	}

	std::cout << "\n=== TEST 2: Full Inventory (4 slots) ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "[MateriaSource] Learned Ice and Cure" << std::endl;
		
		ICharacter* hero = new Character("hero");
		ICharacter* enemy = new Character("enemy");
		
		std::cout << "\n[Character 'hero'] Starting inventory: [empty] [empty] [empty] [empty]" << std::endl;
		
		// Equipaggia 4 materie
		std::cout << "\n[Equipping] Adding materia #1..." << std::endl;
		AMateria* m1 = src->createMateria("ice");
		hero->equip(m1);
		std::cout << "  -> Inventory: [ice] [empty] [empty] [empty]" << std::endl;
		
		std::cout << "[Equipping] Adding materia #2..." << std::endl;
		AMateria* m2 = src->createMateria("cure");
		hero->equip(m2);
		std::cout << "  -> Inventory: [ice] [cure] [empty] [empty]" << std::endl;
		
		std::cout << "[Equipping] Adding materia #3..." << std::endl;
		AMateria* m3 = src->createMateria("ice");
		hero->equip(m3);
		std::cout << "  -> Inventory: [ice] [cure] [ice] [empty]" << std::endl;
		
		std::cout << "[Equipping] Adding materia #4..." << std::endl;
		AMateria* m4 = src->createMateria("cure");
		hero->equip(m4);
		std::cout << "  -> Inventory: [ice] [cure] [ice] [cure] (FULL)" << std::endl;
		
		// Prova ad equipaggiare una 5a materia
		std::cout << "\n[Equipping] Trying to add materia #5 (inventory is FULL)..." << std::endl;
		AMateria* m5 = src->createMateria("ice");
		hero->equip(m5);
		std::cout << "  -> REJECTED! Inventory still: [ice] [cure] [ice] [cure]" << std::endl;
		delete (m5);// Va eliminata manualmente perché non è stata equipaggiata
		
		// Usa tutte e 4 le materie
		std::cout << "\n[Actions] Using all 4 inventory slots:" << std::endl;
		std::cout << "  Slot 0: "; hero->use(0, *enemy);
		std::cout << "  Slot 1: "; hero->use(1, *enemy);
		std::cout << "  Slot 2: "; hero->use(2, *enemy);
		std::cout << "  Slot 3: "; hero->use(3, *enemy);
		
		delete (enemy);
		delete (hero);
		delete (src);
	}

	std::cout << "\n=== TEST 3: Unequip (no delete) ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me");
		ICharacter* target = new Character("target");
		AMateria* ice = src->createMateria("ice");
		
		std::cout << "[Character 'me'] Inventory: [empty] [empty] [empty] [empty]" << std::endl;
		me->equip(ice);
		std::cout << "  -> After equip: [ice] [empty] [empty] [empty]" << std::endl;
		
		std::cout << "\n[Action] Using slot 0 BEFORE unequip:" << std::endl;
		std::cout << "  "; me->use(0, *target);
		
		// NB: unequip non elimina la materia
		std::cout << "\n[Unequip] Removing materia from slot 0..." << std::endl;
		me->unequip(0);
		std::cout << "  -> After unequip: [empty] [empty] [empty] [empty]" << std::endl;
		std::cout << "  -> The Ice materia still exists in memory at address: " << ice << std::endl;
		
		std::cout << "\n[Action] Using slot 0 AFTER unequip (should do nothing):" << std::endl;
		std::cout << "  "; me->use(0, *target); // Non dovrebbe fare nulla
		std::cout << "(no output = slot is empty)" << std::endl;
		
		// Si puo' ancora usare la materia direttamente
		std::cout << "\n[Action] Using the unequipped materia DIRECTLY from memory:" << std::endl;
		std::cout << "  "; ice->use(*target);
		
		std::cout << "\n[Important] We must delete the unequipped materia manually:" << std::endl;
		delete (ice);
		std::cout << "  -> Ice materia deleted" << std::endl;
		
		delete (target);
		delete (me);
		delete (src);
	}

	std::cout << "\n=== TEST 4: Unknown Materia Type ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		std::cout << "[MateriaSource] Learned templates: [ice] [empty] [empty] [empty]" << std::endl;
		
		// Prova a creare un tipo non imparato
		std::cout << "\n[MateriaSource] Trying to create 'fire' materia..." << std::endl;
		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "  -> Correctly returned NULL (type 'fire' was never learned)" << std::endl;
		else
		{
			std::cout << "  -> ERROR: Should have returned NULL" << std::endl;
			delete (unknown);
		}
		
		std::cout << "\n[MateriaSource] Trying to create 'ice' materia (learned)..." << std::endl;
		AMateria* known = src->createMateria("ice");
		if (known != NULL)
		{
			std::cout << "  -> SUCCESS: Created materia of type '" << known->getType() << "'" << std::endl;
			delete (known);
		}
		
		delete (src);
	}

	std::cout << "\n=== TEST 5: Deep Copy of Character ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* original = new Character("original");
		std::cout << "[Character 'original'] Inventory: [empty] [empty] [empty] [empty]" << std::endl;
		original->equip(src->createMateria("ice"));
		std::cout << "  -> After equip #1: [ice] [empty] [empty] [empty]" << std::endl;
		original->equip(src->createMateria("cure"));
		std::cout << "  -> After equip #2: [ice] [cure] [empty] [empty]" << std::endl;
		
		std::cout << "\n[Deep Copy] Creating copy of 'original'..." << std::endl;
		Character copy = Character("copy");// Deep copy usando l'operatore di assegnamento
		copy = *(dynamic_cast<Character*>(original));
		std::cout << "  -> Copy inventory: [ice] [cure] [empty] [empty]" << std::endl;
		
		ICharacter* target = new Character("target");
		
		std::cout << "\n[Actions] Original character using its materias:" << std::endl;
		std::cout << "  Slot 0: "; original->use(0, *target);
		std::cout << "  Slot 1: "; original->use(1, *target);
		
		std::cout << "\n[Actions] Copy character using its OWN materias (independent):" << std::endl;
		std::cout << "  Slot 0: "; copy.use(0, *target);
		std::cout << "  Slot 1: "; copy.use(1, *target);
		
		std::cout << "\nBoth work independently - deep copy successful" << std::endl;
		
		delete (target);
		delete (original);
		delete (src);
	}

	std::cout << "\n=== TEST 6: Invalid Indices ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me");
		ICharacter* target = new Character("target");
		
		me->equip(src->createMateria("ice"));
		std::cout << "[Character 'me'] Inventory: [ice] [empty] [empty] [empty]" << std::endl;
		
		std::cout << "\n[Action] Using VALID index 0:" << std::endl;
		std::cout << "  "; me->use(0, *target);
		
		std::cout << "\n[Action] Using INVALID indices (should do nothing):" << std::endl;
		std::cout << "  Index -1: "; me->use(-1, *target);
		std::cout << "(no output)" << std::endl;
		std::cout << "  Index 4 (out of range): "; me->use(4, *target);
		std::cout << "(no output)" << std::endl;
		std::cout << "  Index 10 (way out): "; me->use(10, *target);
		std::cout << "(no output)" << std::endl;
		
		std::cout << "\n[Action] Unequipping INVALID indices (should do nothing):" << std::endl;
		std::cout << "  Unequip index -1..." << std::endl;
		me->unequip(-1);
		std::cout << "  Unequip index 4..." << std::endl;
		me->unequip(4);
		std::cout << "  -> Inventory unchanged: [ice] [empty] [empty] [empty]" << std::endl;
		
		std::cout << "\n[Verification] Slot 0 still works after invalid operations:" << std::endl;
		std::cout << "  "; me->use(0, *target);
		
		delete (target);
		delete (me);
		delete (src);
	}

	std::cout << "\n=== TEST 7: MateriaSource Capacity (4 templates) ===" << std::endl;
	{
		MateriaSource* src = new MateriaSource();
		
		// Impara 4 materie (limite)
		std::cout << "[MateriaSource] Templates: [empty] [empty] [empty] [empty]" << std::endl;
		std::cout << "\n[Learning] Template #1..." << std::endl;
		src->learnMateria(new Ice());
		std::cout << "  -> Templates: [ice] [empty] [empty] [empty]" << std::endl;
		
		std::cout << "[Learning] Template #2..." << std::endl;
		src->learnMateria(new Cure());
		std::cout << "  -> Templates: [ice] [cure] [empty] [empty]" << std::endl;
		
		std::cout << "[Learning] Template #3..." << std::endl;
		src->learnMateria(new Ice());
		std::cout << "  -> Templates: [ice] [cure] [ice] [empty]" << std::endl;
		
		std::cout << "[Learning] Template #4..." << std::endl;
		src->learnMateria(new Cure());
		std::cout << "  -> Templates: [ice] [cure] [ice] [cure] (FULL)" << std::endl;
		
		std::cout << "\n[Learning] Trying to learn template #5 (source is FULL)..." << std::endl;
		AMateria* extra = new Ice();
		src->learnMateria(extra);
		std::cout << "  -> REJECTED. Templates still: [ice] [cure] [ice] [cure]" << std::endl;
		delete (extra);// Va eliminata manualmente perché non è stata equipaggiata
		
		// Verifico che possa ancora creare materie dai template
		std::cout << "\n[Creating] Creating materias from learned templates:" << std::endl;
		AMateria* m1 = src->createMateria("ice");
		std::cout << "  -> Created materia #1: " << (m1 ? m1->getType() : "NULL") << std::endl;
		AMateria* m2 = src->createMateria("cure");
		std::cout << "  -> Created materia #2: " << (m2 ? m2->getType() : "NULL") << std::endl;
		
		if (m1 && m2)
		{
			ICharacter* test = new Character("test");
			std::cout << "\n[Actions] Using created materias:" << std::endl;
			std::cout << "  "; m1->use(*test);
			std::cout << "  "; m2->use(*test);
			delete (test);
		}
		delete (m1);
		delete (m2);
		delete (src);
	}
	return (0);
}
