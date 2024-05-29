/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:54:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 13:18:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		bool _gateKeeperMode;
		
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(const std::string& name);
		ScavTrap &operator=(const ScavTrap &src);
		virtual ~ScavTrap();

		virtual void attack(const std::string& target) override;
		void guardGate();
};