/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:32:19 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/31 16:41:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#define SLOTS_SIZE 4

class Character: public ICharacter {
	private:
		std::string const name;
		AMateria* slot[SLOTS_SIZE];

	public:
		Character();
		Character(std::string const& name);
		Character(const Character &other);
		Character& operator=(const Character& other);
		virtual ~Character();

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};