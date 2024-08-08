/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/08 21:35:31 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	Handler handlers[] =
	{
		{"char", std::regex(R"(^[\x20-\x7E]$)"), handleChar},
		{"int", std::regex(R"(^[-+]?\d+$)"), handleInt},
		{"float", std::regex(R"(^[-+]?\d+\.\d+f$)"), handleFloat},
		{"double", std::regex(R"(^[-+]?\d+\.\d+$)"), handleDouble},
		{"special", std::regex(R"(^[-+]inff$|^[-+]inf$|^nanf$|^nan$)"), handleSpecial}
	};

	for (const auto& handler : handlers)
	{
		if (std::regex_match(literal, handler.pattern))
		{
			try
			{
				handler.func(literal);
				return;
			}
			catch (...)
			{
				printImpossible();
				return;
			}
		}
	}

	printImpossible();
}

void ScalarConverter::handleChar(const std::string& literal)
{
	char c = literal[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::handleInt(const std::string& literal)
{
	try {
		int i = std::stoi(literal);
		if (i >= -128 && i <= 127)
			printChar(static_cast<char>(i));
		else
			std::cout << "char: impossible" << std::endl;
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
	} catch (const std::out_of_range&) {
		handleFloat(literal);
	}
}

void ScalarConverter::handleFloat(const std::string& literal)
{
	try {
		float f = std::stof(literal);
		double d = static_cast<double>(f);
		if (f >= -128 && f <= 127)
			printChar(static_cast<char>(f));
		else
			std::cout << "char: impossible" << std::endl;
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
			printInt(static_cast<int>(f));
		else
			std::cout << "int: impossible" << std::endl;
		printFloat(f);
		printDouble(static_cast<double>(f));
	} catch (const std::out_of_range&) {
		handleDouble(literal);
	}
} 

void ScalarConverter::handleDouble(const std::string& literal)
{
	try {
		double d = std::stod(literal);
		if (d >= -128 && d <= 127)
			printChar(static_cast<char>(d));
		else
			std::cout << "char: impossible" << std::endl;
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
			printInt(static_cast<int>(d));
		else
			std::cout << "int: impossible" << std::endl;
		if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
			printFloat(static_cast<float>(d));
		else
			std::cout << "float: impossible" << std::endl;
		printDouble(d);
	} catch (const std::out_of_range&) {
		printImpossible();
	}
}

void ScalarConverter::handleSpecial(const std::string& literal)
{
	if (literal == "nanf" || literal == "nan")
		printSpecial("nan");
	else if (literal == "+inff" || literal == "+inf")
		printSpecial("+inf");
	else if (literal == "-inff" || literal == "-inf")
		printSpecial("-inf");
}

void ScalarConverter::printSpecial(const std::string& special)
{
	if (special == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (special == "+inf")
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (special == "-inf")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (f == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (d == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}
