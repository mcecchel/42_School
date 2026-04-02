/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:04:34 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/31 13:47:00 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Funz template per stampare il contenuto di un container tramite iteratori
template <typename C>
void printContainer(const std::string& label, C& container)
{
	std::cout << label << ": ";
	typename C::iterator itb  = container.begin();
	typename C::iterator ite = container.end();
	while (itb != ite)
	{
		std::cout << *itb;
		++itb;
		if (itb != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main(void)
{
	// --- Test del subject (esatto) ---
	std::cout << "=== Subject tests ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);// Aggiunge 17 in cima allo stack
		std::cout << mstack.top() << std::endl;// 17 dovrebbe essere in cima
		mstack.pop();// Rimuove 17
		std::cout << mstack.size() << std::endl;// La size torna a 1
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		// begin e end sono disponibili grazie a MutantStack e iterano su 'c' (il container sottostante protetto di std::stack)
		MutantStack<int>::iterator itb  = mstack.begin();// punta al primo elemento (:5)
		MutantStack<int>::iterator ite = mstack.end();// punta a dopo l'ultimo elemento (:0)
		// Operazioni a vuoto per mostrare che l'iteratore e' bidirezionale
		++itb;
		--itb;
		while (itb != ite)
		{
			std::cout << *itb << std::endl;
			++itb;
		}
		// Costruisco std::stack normale da MutantStack
		std::stack<int> stack(mstack);
		std::cout << "std::stack size: " << stack.size() << std::endl;
	}
	
	// --- Stesso output con std::list (test da subject) ---
	std::cout << "\n=== Same test with std::list (must work the same)===" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		// Stesso pattern del subject, ma con std::list serve per confrontare output
		std::list<int>::iterator itb = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++itb;
		--itb;
		while (itb != ite)
		{
			std::cout << *itb << std::endl;
			++itb;
		}
	}
	
	// --- Test iteratori reverse ---
	std::cout << "\n=== Reverse iterators ===" << std::endl;
	{
		MutantStack<int> mutant;
		mutant.push(1);
		mutant.push(2);
		mutant.push(3);
		mutant.push(4);
		mutant.push(5);

		// reverse begin parte dall'elem in cima allo stack (ordine inverso rispetto a begin/end)
		MutantStack<int>::reverse_iterator ritb  = mutant.rev_begin();
		MutantStack<int>::reverse_iterator rite = mutant.rev_end();
		while (ritb != rite)
		{
			std::cout << *ritb << " ";
			++ritb;
		}
		std::cout << std::endl;
	}
	
	// --- Test con tipo non-int ---
	std::cout << "\n=== MutantStack<std::string> ===" << std::endl;
	{
		MutantStack<std::string> mutant;
		mutant.push("Hello");
		mutant.push("World");
		mutant.push("42");
		MutantStack<std::string>::iterator itb  = mutant.begin();
		MutantStack<std::string>::iterator ite = mutant.end();
		while (itb != ite)
		{
			std::cout << *itb << std::endl;
			++itb;
		}
	}
	return (0);
}