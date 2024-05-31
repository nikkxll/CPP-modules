/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:34:00 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/31 11:42:13 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cout << "Cat Brain allocation failed in default constructor" << std::endl;
		exit(1);
	}
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal()
{
	this->type = other.type;
	this->brain = new Brain();
	if (!this->brain)
	{
		std::cout << "Cat Brain allocation failed in copy constructor" << std::endl;
		exit(1);
	}
	*this->brain = *other.brain;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->type << ": ***meow, meow***" << std::endl;
}

const std::string* Cat::getIdeas() const
{
	return this->brain->getIdeas();
}

std::string Cat::getIdea(int pos) const
{
	return (pos >= 0 && pos < IDEAS_SIZE) ? this->brain->getIdea(pos) : "";
}

void Cat::setIdea(int pos, std::string idea)
{
	if (pos >= 0 && pos < IDEAS_SIZE)
	{
		this->brain->setIdea(pos, idea);
	}
}