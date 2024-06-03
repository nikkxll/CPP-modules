/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:24:00 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/03 16:23:45 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < _maxMaterias; ++i)
		_learnedMaterias[i] = nullptr;
	// std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < _maxMaterias; ++i)
		_learnedMaterias[i] = other._learnedMaterias[i] ? other._learnedMaterias[i]->clone() : nullptr;
	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < _maxMaterias; ++i)
		{
			delete this->_learnedMaterias[i];
			_learnedMaterias[i] = other._learnedMaterias[i] ? other._learnedMaterias[i]->clone() : nullptr;
		}
	}
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _maxMaterias; ++i)
	{
		delete this->_learnedMaterias[i];
	}
	// std::cout << "MateriaSource default destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < _maxMaterias; ++i)
		{
			if (_learnedMaterias[i] == nullptr)
			{
				_learnedMaterias[i] = m;
				std::cout << "Materia " << m->getType() << " learned" << std::endl;
				return;
			}
		}
		delete m;
		std::cout << "Couldn't learn more than 4 Materias" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < _maxMaterias; ++i)
	{
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
		{
			std::cout << "Materia " << _learnedMaterias[i]->getType() << " created" << std::endl;
			return _learnedMaterias[i]->clone();
		}
	}
	std::cout << type << " materia does not exist" << std::endl;
	return nullptr;
}
