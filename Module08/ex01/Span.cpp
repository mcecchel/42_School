/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:43:35 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/26 18:12:27 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Imposto la size a 0 cosi' non ci si puo' aggiungere numeri
Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& copy) : _data(copy._data), _maxSize(copy._maxSize) {}

Span& Span::operator=(const Span& copy) {
	if (this != &copy)
	{
		_data = copy._data;
		_maxSize = copy._maxSize;
	}
	return (*this);
}

Span::~Span() {}

// Per trovare lo span piu' corto devo ordinare il vettore e confronto ogni elemento con il successivo

void	Span::addNumber(int n) {
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_data.push_back(n);
}

int	Span::shortestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers for the span");
	// Creo copia per non alterare l'ordine originale
	std::vector<int> sortedData(_data);
	std::sort(sortedData.begin(), sortedData.end());
	// Inizializzo con la differenza tra i primi due elem
	int minSpan = sortedData[1] - sortedData[0];
	std::size_t i = 2;
	while (i < sortedData.size())
	{
		int diff = sortedData[i] - sortedData[i - 1];
		if (diff < minSpan)
			minSpan = diff;
		++i;
	}
	return (minSpan);
}

int	Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers for the span");
	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());
	return (max - min);
}