/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:38:06 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/19 15:13:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {
	private:
		static bool isChar(const std::string&);
		static bool isInteger(const std::string&);
		static bool isFloat(const std::string&);
		static bool isDouble(const std::string&);
		static void handleFloatPseudoLiterals(const std::string&);
		static void handleDoublePseudoLiterals(const std::string&);
		static void printValues(char, int, float, double);

	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;

		static void convert(const std::string&);
};