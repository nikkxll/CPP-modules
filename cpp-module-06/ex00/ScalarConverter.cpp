/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/07/26 14:27:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	Handler handlers[] =
	{
		{"char", std::regex(R"(^'[\x20-\x7E]'$)"), handleChar},
		{"int", std::regex(R"(^[-+]?\d+$)"), handleInt},
		{"float", std::regex(R"(^[-+]?\d+\.\d+f$)"), handleFloat},
		{"double", std::regex(R"(^[-+]?\d+\.\d+$)"), handleDouble},
		{"special", std::regex(R"(^[-+]?inff$|^[-+]?inf$|^nanf?$)"), handleSpecial}
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
				std::cout << "Invalid literal" << std::endl;
				return;
			}
		}
	}

	std::cout << "Invalid literal" << std::endl;
}

void ScalarConverter::handleChar(const std::string& literal)
{
	char c = literal[1];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::handleInt(const std::string& literal)
{
	int i = std::stoi(literal);
	printChar(static_cast<char>(i));
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void ScalarConverter::handleFloat(const std::string& literal)
{
	float f = std::stof(literal);
	printChar(static_cast<char>(f));
	printInt(static_cast<int>(f));
	printFloat(f);
	printDouble(static_cast<double>(f));
} 

void ScalarConverter::handleDouble(const std::string& literal)
{
	double d = std::stod(literal);
	printChar(static_cast<char>(d));
	printInt(static_cast<int>(d));
	printFloat(static_cast<float>(d));
	printDouble(d);
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

void ScalarConverter::printChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
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

int main(int ac, char **av)
{
	// ScalarConverter a;

	(void)ac;
	(void)av;
		
	ScalarConverter::convert("-10000");
	std::cout << std::endl;
	ScalarConverter::convert("100000000000000000");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("'a'");
	std::cout << std::endl;
	ScalarConverter::convert("'100'");
	std::cout << std::endl;
	ScalarConverter::convert("\\");
	std::cout << std::endl;
	ScalarConverter::convert("hahaha");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("421212423423423.23423743275435");
	std::cout << std::endl;
	ScalarConverter::convert("421212423423423.23423743275435f");
	std::cout << std::endl;
	ScalarConverter::convert("1000.0000000f");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	
	// if (ac == 2)
	// 	ScalarConverter::convert(av[1]);
		
	return 0;
}
