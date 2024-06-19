/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/19 15:19:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str)
{
	if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf")
	{
		handleFloatPseudoLiterals(str);
		return;
	}

	if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan")
	{
		handleDoublePseudoLiterals(str);
		return;
	}
}

bool ScalarConverter::isChar(const std::string& str)
{
	return str.length() == 3 && str[0] == '\''
		&& str[2] == '\'' && std::isprint(str[1]);
}
	
bool ScalarConverter::isInteger(const std::string& str)
{
	if (str.empty())
	{
		return false;
	}
	
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	for (; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str.empty() || str[str.length() - 1] != 'f')
	{
		return false;
	}

	try {
		std::stof(str);
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str.empty())
	{
		return false;
	}
	
	try {
		std::stod(str);
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

void ScalarConverter::printValues(char charValue, int intValue,
	float floatValue, double doubleValue)
{
	if (std::isprint(charValue)) {
		std::cout << "char: '" << charValue << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << intValue << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << floatValue << "f" << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::handleFloatPseudoLiterals(const std::string& str)
{
	char charValue;
	int intValue;
	float floatValue;
	double doubleValue;

	if (str == "+inff" || str == "inff")
	{
		floatValue = std::numeric_limits<float>::infinity();
	}
	else if (str == "-inff")
	{
		floatValue = -std::numeric_limits<float>::infinity();
	}
	else
	{
		floatValue = std::numeric_limits<float>::quiet_NaN();
	}
	doubleValue = static_cast<double>(floatValue);
	charValue = static_cast<char>(floatValue);
	intValue = static_cast<int>(floatValue);
	printValues(charValue, intValue, floatValue, doubleValue);
}

void ScalarConverter::handleDoublePseudoLiterals(const std::string& str)
{
	char charValue;
	int intValue;
	float floatValue;
	double doubleValue;

	if (str == "+inf" || str == "inf")
	{
		doubleValue = std::numeric_limits<double>::infinity();
	}
	else if (str == "-inf")
	{
		doubleValue = -std::numeric_limits<double>::infinity();
	}
	else
	{
		doubleValue = std::numeric_limits<double>::quiet_NaN();
	}
	floatValue = static_cast<float>(doubleValue);
	charValue = static_cast<char>(doubleValue);
	intValue = static_cast<int>(doubleValue);
	printValues(charValue, intValue, floatValue, doubleValue);
}