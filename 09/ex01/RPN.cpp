/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:17:11 by mcecchel          #+#    #+#             */
/*   Updated: 2026/04/13 16:54:03 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &copy) : _stack(copy._stack) {}
RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}
RPN::~RPN() {}

void RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: not enough arguments");

	int b = _stack.top(); _stack.pop();// Operando DX (secondo)
	int a = _stack.top(); _stack.pop();// Operando SX (primo)
	int res;

	if (op == '+')
		res = a + b;
	else if (op == '-')
		res = a - b;
	else if (op == '*')
		res = a * b;
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		res = a / b;
	}
	else
		throw std::runtime_error("Error");
	_stack.push(res);
}

int	RPN::evaluateExpression(const std::string& expr)
{
	// Pulisco lo stack prima di valutare una nuova espressione
	while (!_stack.empty())
		_stack.pop();
	
	std::istringstream	iss(expr);
	std::string			token;
	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0])) {
			// E' una cifra singola > si pusha come int
			_stack.push(token[0] - '0');
		}
		else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' ||
				  token[0] == '*' || token[0] == '/')) {
			applyOperator(token[0]);
		}
		else {
			throw std::runtime_error("Error: not a valid token");
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Error: not a valid  expression");// Per espressioni come "3 4" o "3 +"
	}
	return (_stack.top());
}