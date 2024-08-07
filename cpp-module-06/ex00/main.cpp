/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:34 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/07 11:34:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
