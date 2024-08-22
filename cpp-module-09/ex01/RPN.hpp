/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:52:56 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/22 17:15:31 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream> 
#include <stack>
#include <stdexcept>

class RPN {
	private:
		static std::stack<int>	_stack;
		static bool				isOperation(char c);
		static int				executeOperation(int a, int b, char c);

		RPN() = delete;
		RPN(const RPN &) = delete;
		RPN& operator=(const RPN &) = delete;
		~RPN() = delete;
	public:
		static void				execute(char *arg);
};