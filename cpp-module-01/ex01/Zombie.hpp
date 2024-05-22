/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:27:16 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/21 15:33:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string	name;
		
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		void announce(void);
		void setZombieName(std::string name);
};

#endif