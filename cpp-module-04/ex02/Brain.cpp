/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:48:26 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/30 13:57:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < IDEAS_SIZE; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < IDEAS_SIZE; ++i)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string* Brain::getIdeas() const
{
	return this->ideas;
}

std::string Brain::getIdea(int pos) const
{
	return (pos >= 0 && pos < IDEAS_SIZE) ? this->ideas[pos] : "";
}

void Brain::setIdea(int pos, std::string idea)
{
	if (pos >= 0 && pos < IDEAS_SIZE)
	{
		this->ideas[pos] = idea;
	}
}