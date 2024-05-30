/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:21:07 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/30 14:47:13 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cout << "Dog Brain allocation failed in default constructor" << std::endl;
		exit(1);
	}
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	this->type = other.type;
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cout << "Dog Brain allocation failed in copy constructor" << std::endl;
		exit(1);
	}
	*this->brain = *other.brain;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain();
		if (!this->brain)
		{
			std::cout << "Dog Brain allocation failed in assignment operator" << std::endl;
			exit(1);
		}
		*this->brain = *other.brain;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << ": ***woof, woof***" << std::endl;
}

const std::string* Dog::getIdeas() const
{
	return this->brain->getIdeas();
}

std::string Dog::getIdea(int pos) const
{
	return (pos >= 0 && pos < IDEAS_SIZE) ? this->brain->getIdea(pos) : "";
}

void Dog::setIdea(int pos, std::string idea)
{
	if (pos >= 0 && pos < IDEAS_SIZE)
	{
		this->brain->setIdea(pos, idea);
	}
}