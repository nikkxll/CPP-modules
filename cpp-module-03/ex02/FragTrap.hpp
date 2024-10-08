/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:07:34 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/29 13:19:09 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	private:
		
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(const std::string& name);
		FragTrap &operator=(const FragTrap &src);
		virtual ~FragTrap();

		void highFivesGuys();
};