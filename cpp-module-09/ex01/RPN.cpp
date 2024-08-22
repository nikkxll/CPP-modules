/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:02 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/22 17:13:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

std::stack<int>	RPN::_stack;

bool RPN::isOperation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::executeOperation(int a, int b, char c)
{
	if (c == '+') return b + a;
	else if (c == '-') return b - a;
	else if (c == '*') return b * a;
	else if (c == '/' && a != 0) return b / a;
	else throw std::runtime_error("Error");
}

void RPN::execute(char *arg)
{
	bool digit_flag = false;
	std::string expression(arg);
	
	for (char it: expression) {
		if (std::isspace(it)) digit_flag = false;
		else if (std::isdigit(it) && digit_flag == false) {
			digit_flag = true;
			_stack.push(it - '0');
		}
		else if (isOperation(it)) {
			if (_stack.size() < 2) throw std::runtime_error("Error");
			digit_flag = false;
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			_stack.push(executeOperation(a, b, it));
		}
		else throw std::runtime_error("Error");
	}
	if (_stack.size() != 1) throw std::runtime_error("Error");
	std::cout << _stack.top() << std::endl;
}
