/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:30 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 12:45:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string& type) : type(type)
{
}

const std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}