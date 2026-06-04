/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:41:20 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/15 17:19:25 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>
# include <vector>
# include <deque>
# include <string>
# include <algorithm>
# include <ctime>

class PmergeMe {
private: 
	std::vector<int>	_vector;
	std::deque<int>		_deque;

	// Algoritmo Ford-Johnson per vector
	void	fjVector(std::vector<int>& vec);
	void	insertPendVector(std::vector<int>& base, const std::vector<int>& pend,
		const std::vector<std::size_t>& jacobsthal);
	// Algoritmo Ford-Johnson per deque
	void	fjDeque(std::deque<int>& deq);
	void	insertPendDeque(std::deque<int>& base, const std::deque<int>& pend,
		const std::vector<std::size_t>& jacobsthal);
	// Costruisce la sequenza di Jacobsthal fino a n elementi
	std::vector<std::size_t> createJacobsthal(size_t n) const;

public:
	//OCF
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	void	parseInput(int ac, char **av);
	void	sort();
};

#endif