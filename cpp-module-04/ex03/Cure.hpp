/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:08:44 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/31 13:53:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(std::string const& type);
		Cure(const Cure &other);
		Cure& operator=(const Cure& other);
		~Cure();
		
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};