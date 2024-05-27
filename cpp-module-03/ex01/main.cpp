/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:22:33 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/27 22:55:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap	a("CT1");
	ClapTrap	b("CT2");
	ScavTrap	c("ST1");
	ScavTrap	d("Enemy");

	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
	a.attack("Enemy");
	d.takeDamage(0);
	b.attack("Enemy");
	d.takeDamage(0);
	c.attack("Enemy");
	d.takeDamage(20);
	d.beRepaired(5);
	d.attack("ST1");
	d.attack("ST1");
	d.attack("CT2");
	c.takeDamage(40);
	b.takeDamage(20);
	c.guardGate();
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
	c.attack("Enemy");
	c.attack("Enemy");
	c.attack("Enemy");
	c.attack("Enemy");
	d.takeDamage(80);
	c.guardGate();
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
}