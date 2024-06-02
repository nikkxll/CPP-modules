/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:32:19 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/03 00:17:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string const _name;
		static const int _size = 4;
		static const int _unequippedSize = 1000;
		AMateria* _slot[_size];
		AMateria* _unequipped[_unequippedSize];

	public:
		Character();
		Character(std::string const&);
		~Character() override;
		Character(const Character &);
		Character& operator=(const Character &);

		std::string const& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
		void setUnequipped(AMateria* ptr);
};