/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:33:55 by mcecchel          #+#    #+#             */
/*   Updated: 2026/03/09 14:37:02 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
public:
	static void convert(const std::string& literal);
};

#endif