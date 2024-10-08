/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/08 17:55:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <iomanip>
#include <math.h>

struct Handler
{
	const char* typeName;
	std::regex pattern;
	std::function<void(const std::string&)> func;
};

class ScalarConverter {
	private:
		static void printChar(char);
		static void printInt(int);
		static void printFloat(float);
		static void printDouble(double);
		static void printSpecial(const std::string& special);
		static void handleChar(const std::string& literal);
		static void handleInt(const std::string& literal);
		static void handleFloat(const std::string& literal);
		static void handleDouble(const std::string& literal);
		static void handleSpecial(const std::string& literal);
		static void printImpossible();
		static void handleConversion(const std::string& literal);
		
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;

		static void convert(const std::string&);
};