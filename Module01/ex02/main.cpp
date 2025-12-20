/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:59:28 by mcecchel          #+#    #+#             */
/*   Updated: 2025/12/20 18:25:46 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	// Stringa originale
	std::string str = "HI THIS IS BRAIN";
	// Pointer alla stringa
	std::string* stringPTR = &str;
	// Reference alla stringa
	std::string& stringREF = str;
	
	std::cout << "\n[Memory addresses]" << std::endl;
	std::cout << " Address of str: " << &str << std::endl;
	std::cout << " Address in stringPTR: " << stringPTR << std::endl;
	std::cout << " Address of stringREF: " << &stringREF << std::endl;

	std::cout << "\n[Values]" << std::endl;
	std::cout << " Value of brain: " << str << std::endl;
	std::cout << " Value of *stringPTR: " << *stringPTR << std::endl;
	std::cout << " Value of stringREF: " << stringREF << std::endl;
	std::cout << "" << std::endl;
	return (0);
}