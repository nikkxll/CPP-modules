/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:34 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/25 23:27:08 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractBitsNum = 8;

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	setRawBits(intValue);
	value = intValue << fractBitsNum;
	std::cout << "Int to fixed constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
	setRawBits(floatValue);
	value = static_cast<int>(roundf(floatValue * (1 << fractBitsNum)));
	std::cout << "Float to fixed constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		value = other.value;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / static_cast<float>(1 << fractBitsNum));
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> fractBitsNum);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}