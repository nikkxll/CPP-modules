/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/27 13:35:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cerr << "No arguments provided"<< std::endl;
	else
		PmergeMe::execute(argc, argv);
}
