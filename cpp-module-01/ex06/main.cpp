/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:39:59 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 22:18:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char const *argv[])
{
	Harl harl;
	
	if (ac != 2)
	{
		std::cout << "Arguments count error" << std::endl;
		return EXIT_FAILURE;
	}
	harl.complain(argv[1]);
	return EXIT_SUCCESS;
}
