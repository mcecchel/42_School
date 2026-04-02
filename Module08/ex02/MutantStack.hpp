/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:53:12 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/31 13:22:19 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Tipo del container sottostante (per default e' std::deque<T>)
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Orthodox Canonical Form
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
	MutantStack& operator=(const MutantStack& copy) {
		if (this != &copy)
			std::stack<T>::operator=(copy);
		return *this;
	}
	~MutantStack() {}

	// Iteratori: permettono di accedere a 'c' (il container protetto di std::stack)
	iterator begin() {
		return (this->c.begin());
	}
	iterator end() {
		return (this->c.end());
	}
	const_iterator begin() const {
		return (this->c.begin());
	}
	const_iterator end() const {
		return (this->c.end());
	}
	reverse_iterator rev_begin() {
		return (this->c.rbegin());
	}
	reverse_iterator rev_end() {
		return (this->c.rend());
	}
	const_reverse_iterator rev_begin() const {
		return (this->c.rbegin());
	}
	const_reverse_iterator rev_end() const {
		return (this->c.rend());
	}
};

#endif