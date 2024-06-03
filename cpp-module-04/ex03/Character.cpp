/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:32:21 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/03 16:44:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown")
{
	for (int i = 0; i < _size; ++i)
		_slot[i] = nullptr;
	for (int i = 0; i < _unequippedSize; ++i)
		_unequipped[i] = nullptr;
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const& name) : _name(name)
{
	for (int i = 0; i < _size; ++i)
		_slot[i] = nullptr;
	for (int i = 0; i < _unequippedSize; ++i)
		_unequipped[i] = nullptr;
	// std::cout << "Character overload constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name + "_copy")
{
	for (int i = 0; i < _size; ++i)
		_slot[i] = other._slot[i] ? other._slot[i]->clone() : nullptr;
	for (int i = 0; i < _unequippedSize; ++i)
		_unequipped[i] = nullptr;
	// std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < _size; ++i)
		{
			delete this->_slot[i];
			this->_slot[i] = nullptr;
			_slot[i] = other._slot[i] ? other._slot[i]->clone() : nullptr;
		}
	}
	std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < _size; ++i)
	{
		delete this->_slot[i];
	}
	for (int i = 0; i < _unequippedSize; ++i)
	{
		delete this->_unequipped[i];
	}
	// std::cout << "Character default destructor called" << std::endl;
}

std::string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int idx = 0;
	if (!m)
	{
		std::cout << "Wrong sort of Materia, nothing added to the slots" << std::endl;
		return;
	}
	while (this->_slot[idx] != nullptr && idx < 4)
		idx++;
	if (idx >= 4)
	{
		std::cout << "Your slots are full, please unequip something first" << std::endl;
		return;
	}
	this->_slot[idx] = m;
	std::cout << "New materia of type " << m->getType() << " equipped successfully at slot ";
	std::cout << idx << " by " << this->_name << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) 
	{
		std::cout << "Index is out of the range, nothing unequipped" << std::endl;
	}
	else if (this->_slot[idx] == nullptr)
	{
		std::cout << "Nothing to unequip at this position" << std::endl;
	}
	else
	{
		std::cout << "Materia of type " << this->_slot[idx]->getType();
		std::cout << " unequipped successfully at slot " << idx << " by " << this->_name << std::endl;
		setUnequipped(this->_slot[idx]);
		this->_slot[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !this->_slot[idx])
	{
		std::cout << "Wrong or empty at index " << idx << std::endl;
		return ;
	}
	this->_slot[idx]->use(target);
}

void Character::setUnequipped(AMateria* ptr)
{
	int idx = 0;
	while (this->_unequipped[idx] != nullptr)
		idx++;
	this->_unequipped[idx] = ptr;
}
