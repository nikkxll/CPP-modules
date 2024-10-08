/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:52:56 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/24 14:26:08 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
	private:
		static std::stack<float>	_stack;
		static bool					isOperation(char c);
		static float				executeOperation(float a, float b, char c);
		static void					processOperation(bool& digit_flag, char c);
		static void					pushNumber(bool& digit_flag, char c);

		RPN() = delete;
		RPN(const RPN &) = delete;
		RPN& operator=(const RPN &) = delete;
		~RPN() = delete;
	public:
		static void					execute(char *arg);
};