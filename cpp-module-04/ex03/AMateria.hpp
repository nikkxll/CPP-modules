/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:44:36 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/02 23:53:42 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		const std::string _type;
		
	public:
		AMateria();
		AMateria(std::string const&);
		virtual ~AMateria();
		AMateria(const AMateria &);
		AMateria& operator=(const AMateria&);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};