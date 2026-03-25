/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:15:59 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/24 15:30:59 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

// Value initialization: per i tipi principali, li setta a 0; per le classi,
// chiama il costruttore di default

template <typename T>
class Array {
private:
	T*				_data;
	unsigned int	_size;
public:
	// Default constructor: array vuoto
	Array() : _data(NULL), _size(0) {}
	// Costruttore con n: alloca n elementi value-initialized
	Array(unsigned int n) : _data(new T[n]()), _size(n) {}
	// Copy constructor: deep copy
	Array(const Array& copy) : _data(NULL), _size(0) {
		*this = copy;
	}
	// Assignment operator: deep copy
	Array& operator=(const Array& copy)
	{
		if (this == &copy)
			return (*this);
		delete[] _data;
		_size = copy._size;
		if (_size > 0)
		{
			_data = new T[_size];
			unsigned int i = 0;
			while (i < _size)
			{
				_data[i] = copy._data[i];
				i++;
			}
		}
		else
			_data = NULL;
		return (*this);
	}
	~Array() {
		delete[] _data;
	}
	// operator[] non const cosi' permette lettura e scrittura
	T& operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::out_of_range("Index out of bounds");
		return (_data[i]);
	}
	// operator[] const cosi' permette solo lettura, senza modificare l'array const
	const T& operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::out_of_range("Index out of bounds");
		return (_data[i]);
	}
	// size() per calcolare n di elementi, non modifica l'array
	unsigned int size() const {
		return (_size);
	}
};

#endif