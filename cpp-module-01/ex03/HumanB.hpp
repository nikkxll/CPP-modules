/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:13:19 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 12:59:31 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		Weapon*	weapon;
		std::string	name;

	public:
		HumanB(const std::string &name);
		~HumanB();
		
		void	attack();
		void	setWeapon(Weapon &weapon);
};

#endif