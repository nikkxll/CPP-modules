/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:22:33 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 18:00:41 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	a("CT1");
	ScavTrap	b("ST1");
	FragTrap	c("FT1");
	ScavTrap	en("Enemy");

	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << en << std::endl;
	std::cout << std::endl;
	a.attack("Enemy");
	en.takeDamage(0);
	b.attack("Enemy");
	en.takeDamage(20);
	c.attack("Enemy");
	en.takeDamage(30);
	en.beRepaired(15);
	en.attack("ST1");
	en.attack("ST1");
	en.attack("FT1");
	b.takeDamage(40);
	c.takeDamage(20);
	b.guardGate();
	c.highFivesGuys();
	std::cout << std::endl;	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << en << std::endl;
	std::cout << std::endl;
	c.attack("Enemy");
	c.attack("Enemy");
	c.attack("Enemy");
	c.attack("Enemy");
	en.takeDamage(120);
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << en << std::endl;
	std::cout << std::endl;
}