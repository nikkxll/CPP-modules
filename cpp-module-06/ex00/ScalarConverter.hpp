/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/29 23:57:35 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <regex>

class ScalarConverter {
	private:
		static bool isInteger(const std::string&);
		static bool isFloat(const std::string&);
		static bool isDouble(const std::string&);
		static bool isChar(const std::string&);
		static void handleFloatPseudoLiterals(std::string&);
		static void handleDoublePseudoLiterals(std::string&);
		static void printValues(char, int, float, double);

	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;

        static void convert(std::string&);
};