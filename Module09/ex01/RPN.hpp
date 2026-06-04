/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:17:20 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/09 14:50:50 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>
# include <stack>
# include <string>

class RPN {
private:
	std::stack<int>	_stack;
	void	applyOperator(char op);
public:
// ocf
	RPN();
	RPN(const RPN &copy);
	RPN& operator=(const RPN &copy);
	~RPN();

	int	evaluateExpression(const std::string& expr);
};

#endif