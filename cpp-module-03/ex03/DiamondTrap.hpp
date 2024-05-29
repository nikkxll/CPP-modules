/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:50 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 13:19:31 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	protected:
		std::string name;
		
	public:
		DiamondTrap();
		DiamondTrap(const std::string);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		virtual ~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
		void display(std::ostream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, DiamondTrap const& clap);