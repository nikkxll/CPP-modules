/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/18 22:27:38 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ScalarConverter {
	private:
		static void isInteger(std::string&);
		static void isFloat(std::string&);
		static void isDouble(std::string&);
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