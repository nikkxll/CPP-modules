/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:41:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/22 22:19:50 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define N_MSG 4

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		int filter(std::string level);
		
	public:
		Harl();
		void complain(std::string level);
};

#endif