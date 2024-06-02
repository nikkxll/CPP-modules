/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:08:51 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/02 23:50:40 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice& operator=(const Ice& other);
		
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};