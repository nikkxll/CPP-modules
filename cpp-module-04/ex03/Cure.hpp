/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:08:44 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/02 23:50:34 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure &);
		Cure& operator=(const Cure&);
		
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};