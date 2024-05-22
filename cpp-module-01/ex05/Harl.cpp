/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:44:47 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 17:13:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn`t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn`t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I`ve been coming for years whereas you started working here since ";
	std::cout << "last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void	(Harl::*HarlMemFoo[N_MSG])(void) =
	{
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	const std::string levels[N_MSG] = 
	{
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (int i = 0; i < N_MSG; i++)
	{
		if (levels[i] == level)
		{
			(this->*HarlMemFoo[i])();
			break ;
		}
	}
}