/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:43:25 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/26 18:21:53 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <vector>

class Span {
private:
	std::vector<int>	_data;
	unsigned int		_maxSize;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	void	addNumber(int n);
	int		shortestSpan() const;
	int		longestSpan() const;

	// Aggiunge un range di elem tramite iteratori
	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end) {
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}
};

#endif