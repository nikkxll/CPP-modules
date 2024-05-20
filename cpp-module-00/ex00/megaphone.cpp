/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:49:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 23:53:48 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string toUpperCase(const std::string& input)
{
	std::string result = input;
	
	for (char& c : result)
		c = std::toupper(c);
	return result;
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
		std::cout << toUpperCase(argv[i]);
	std::cout << std::endl;
	return (0);
}
