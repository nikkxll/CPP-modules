/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:34 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/07 16:24:07 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	if (ac == 2)
		ScalarConverter::convert(av[1]);
		
	return EXIT_SUCCESS;
}
