/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:22:33 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 13:15:57 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap	a("CT1");
	ScavTrap	b("ST1");
	FragTrap	c("FT1");
	DiamondTrap	d("DT1");

	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
	
	d.whoAmI();
	a.attack("DT1");
	d.takeDamage(0);
	b.attack("DT1");
	d.takeDamage(20);
	c.attack("DT1");
	d.takeDamage(30);
	d.beRepaired(40);
	d.attack("ST1");
	d.attack("ST1");
	d.attack("FT1");
	b.takeDamage(60);
	c.takeDamage(30);
	b.guardGate();

	std::cout << std::endl;	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
	
	c.attack("DT1");
	c.attack("DT1");
	c.attack("DT1");
	c.attack("DT1");
	d.takeDamage(120);
	
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
}