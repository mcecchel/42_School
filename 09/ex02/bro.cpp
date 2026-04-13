/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:52:13 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/13 17:03:38 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& copy) : _vector(copy._vector), _deque(copy._deque) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy)
	{
		_vector = copy._vector;
		_deque = copy._deque;
	}
	return (*this);
}
PmergeMe::~PmergeMe() {}

void	PmergeMe::parseInput(int ac, char **av)
{
	int	i = 1;
	while (i < ac)
	{
		std::istringstream iss(av[i]);
		int	nbr;
		if (!(iss >> nbr))
			throw std::invalid_argument("Error: Invalid input. Non-integer value found.");
		if (nbr <= 0)
			throw std::invalid_argument("Error: Invalid input. Only positive integers are allowed.");
		_vector.push_back(nbr);
		_deque.push_back(nbr);
		i++;
	}
}

// Costruisce la sequenza di Jacobsthal fino a n elementi
std::vector<std::size_t> PmergeMe::createJacobsthal(size_t n) const
{
	std::vector<std::size_t> jSequence;
	jSequence.push_back(0);// J(0)
	jSequence.push_back(1);// J(1)
	for (size_t i = 2; jSequence.size() < n; ++i)
	{
		std::size_t next = jSequence[i - 1] + 2 * jSequence[i - 2];
		jSequence.push_back(next);
	}
	return (jSequence);
}

// ===============================================================
// FORD-JOHNSON per std::vector
// ===============================================================
void PmergeMe::insertPendVector(std::vector<int>& main,
								 const std::vector<int>& pend,
								 const std::vector<std::size_t>& jac)
{
	std::size_t n = pend.size();
	std::vector<bool> inserted(n, false);

	// Scorriamo i gruppi di Jacobsthal in o0rdine
	for (std::size_t ji = 2; ji < jac.size(); ji++)
	{
		// Inseriamo da jac[ji]-1 fino a jac[ji-1] (incluso) in ordine decrescente
		std::size_t end   = jac[ji] < n ? jac[ji] : n;
		std::size_t start = jac[ji - 1];

		for (std::size_t k = end; k-- > start; )
		{
			if (k < n && !inserted[k])
			{
				// Il pend[k] può essere inserito solo fino alla posizione
				// del suo vincitore accoppiato, che è main[k+1] (se esiste)
				std::vector<int>::iterator bound;
				if (k + 1 < main.size())
				{
					// Cerca la posizione del vincitore main[k] originale
					// Siccome abbiamo ricostruito main, usiamo lower_bound
					// limitato alla posizione dell'elemento k+1 in main
					bound = std::lower_bound(main.begin(), main.end(), pend[k]);
				}
				else
				{
					bound = std::lower_bound(main.begin(), main.end(), pend[k]);
				}
				main.insert(bound, pend[k]);
				inserted[k] = true;
			}
		}
	}
	// Inserisci eventuali rimanenti
	for (std::size_t k = 0; k < n; k++)
	{
		if (!inserted[k])
		{
			std::vector<int>::iterator pos =
				std::lower_bound(main.begin(), main.end(), pend[k]);
			main.insert(pos, pend[k]);
		}
	}
}

void PmergeMe::fjVector(std::vector<int>& v)
{
	std::size_t n = v.size();
	if (n <= 1)
		return;

	// Caso base: 2 elementi
	if (n == 2)
	{
		if (v[0] > v[1])
			std::swap(v[0], v[1]);
		return;
	}

	// 1. Pairing: separa vincitori e perdenti
	bool hasOdd = (n % 2 != 0);
	std::size_t pairLimit = n;
	int oddEl = 0;
	if (hasOdd)
	{
		pairLimit = n - 1;
		oddEl = v.back();
	}

	std::vector<int> winners, losers;
	for (std::size_t i = 0; i + 1 < pairLimit; i += 2)
	{
		if (v[i] > v[i + 1])
		{
			winners.push_back(v[i]);
			losers.push_back(v[i + 1]);
		}
		else
		{
			winners.push_back(v[i + 1]);
			losers.push_back(v[i]);
		}
	}

	// 2. Ordina ricorsivamente i vincitori
	fjVector(winners);

	// 3. Inserisci il primo perdente (minimo garantito)
	std::vector<int> main_chain;
	main_chain.push_back(losers[0]);
	for (std::size_t i = 0; i < winners.size(); i++)
		main_chain.push_back(winners[i]);

	// 4. Inserisci il resto dei perdenti con Jacobsthal
	std::vector<int> pend(losers.begin() + 1, losers.end());
	std::vector<std::size_t> jac = createJacobsthal(pend.size());
	insertPendVector(main_chain, pend, jac);

	// 5. Gestisci l'elemento dispari
	if (hasOdd)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(main_chain.begin(), main_chain.end(), oddEl);
		main_chain.insert(pos, oddEl);
	}

	v = main_chain;
}

// ===============================================================
// FORD-JOHNSON per std::deque
// ===============================================================
void PmergeMe::insertPendDeque(std::deque<int>& main,
								const std::deque<int>& pend,
								const std::vector<std::size_t>& jac)
{
	std::size_t n = pend.size();
	std::vector<bool> inserted(n, false);

	for (std::size_t ji = 2; ji < jac.size(); ji++)
	{
		std::size_t end   = jac[ji] < n ? jac[ji] : n;
		std::size_t start = jac[ji - 1];

		for (std::size_t k = end; k-- > start; )
		{
			if (k < n && !inserted[k])
			{
				std::deque<int>::iterator pos =
					std::lower_bound(main.begin(), main.end(), pend[k]);
				main.insert(pos, pend[k]);
				inserted[k] = true;
			}
		}
	}
	for (std::size_t k = 0; k < n; k++)
	{
		if (!inserted[k])
		{
			std::deque<int>::iterator pos =
				std::lower_bound(main.begin(), main.end(), pend[k]);
			main.insert(pos, pend[k]);
		}
	}
}

void PmergeMe::fjDeque(std::deque<int>& d)
{
	std::size_t n = d.size();
	if (n <= 1)
		return;

	if (n == 2)
	{
		if (d[0] > d[1])
			std::swap(d[0], d[1]);
		return;
	}

	bool hasOdd = (n % 2 != 0);
	std::size_t pairLimit = n;
	int oddEl = 0;
	if (hasOdd)
	{
		pairLimit = n - 1;
		oddEl = d.back();
	}

	std::deque<int> winners, losers;
	for (std::size_t i = 0; i + 1 < pairLimit; i += 2)
	{
		if (d[i] > d[i + 1])
		{
			winners.push_back(d[i]);
			losers.push_back(d[i + 1]);
		}
		else
		{
			winners.push_back(d[i + 1]);
			losers.push_back(d[i]);
		}
	}

	fjDeque(winners);

	std::deque<int> main_chain;
	main_chain.push_back(losers[0]);
	for (std::size_t i = 0; i < winners.size(); i++)
		main_chain.push_back(winners[i]);

	std::deque<int> pend(losers.begin() + 1, losers.end());
	std::vector<std::size_t> jac = createJacobsthal(pend.size());
	insertPendDeque(main_chain, pend, jac);

	if (hasOdd)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(main_chain.begin(), main_chain.end(), oddEl);
		main_chain.insert(pos, oddEl);
	}

	d = main_chain;
}

// -------------------------------------------------------
// Funzione principale: esegue entrambi, misura il tempo
// -------------------------------------------------------
void PmergeMe::sort()
{
	// Stampa sequenza non ordinata
	std::cout << "Before: ";
	for (std::size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i];
		if (i + 1 < _vector.size()) std::cout << " ";
	}
	std::cout << std::endl;

	// --- Sort con vector ---
	std::vector<int> vecCopy(_vector);
	clock_t startVec = clock();
	fjVector(vecCopy);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec)
					 / CLOCKS_PER_SEC * 1000000.0;

	// --- Sort con deque ---
	std::deque<int> deqCopy(_deque);
	clock_t startDeq = clock();
	fjDeque(deqCopy);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq)
					 / CLOCKS_PER_SEC * 1000000.0;

	// Stampa sequenza ordinata
	std::cout << "After:  ";
	for (std::size_t i = 0; i < vecCopy.size(); i++)
	{
		std::cout << vecCopy[i];
		if (i + 1 < vecCopy.size()) std::cout << " ";
	}
	std::cout << std::endl;

	// Stampa tempi
	std::cout << "Time to process a range of " << vecCopy.size()
			  << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deqCopy.size()
			  << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
