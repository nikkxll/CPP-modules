/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:22:33 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/27 16:45:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("CT1");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.takeDamage(3);
	a.takeDamage(6);
	a.attack("CT2");
	b.attack("CT3");
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.beRepaired(4);
	b.attack("CT2");
	b.attack("CT2");
	a.beRepaired(1);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b.takeDamage(12);
	a.takeDamage(9);
	a.beRepaired(5);
	b.attack("CT3");
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}