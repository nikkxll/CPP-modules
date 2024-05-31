/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:08:51 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/31 14:00:35 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(std::string const& type);
		Ice(const Ice &other);
		Ice& operator=(const Ice& other);
		~Ice();
		
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};