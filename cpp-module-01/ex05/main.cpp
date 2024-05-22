/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:39:59 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 17:43:55 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void testing(std::string level)
{
	Harl harl;
	
	std::cout << level << ":" << std::endl;
	harl.complain(level);
}

int main(void)
{
	testing("DEBUG");
	testing("INFO");
	testing("WARNING");
	testing("ERROR");
	testing("DEBUG");
	testing("WARNING");
	testing("WRONG_INPUT");
	
	return EXIT_SUCCESS;
}