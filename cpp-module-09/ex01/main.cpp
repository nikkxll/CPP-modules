/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/22 17:15:00 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong amount of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	
	try {
		RPN::execute(argv[1]);
	} catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}
