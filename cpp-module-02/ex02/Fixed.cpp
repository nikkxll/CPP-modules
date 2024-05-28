/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:34 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/28 18:36:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractBitsNum = 8;
const int Fixed::fractionMask = 0xffffffff >> (32 - fractBitsNum);
const int Fixed::wholeMask = -1 ^ fractionMask;

Fixed::Fixed() : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	setRawBits(intValue);
	value = intValue << fractBitsNum;
	// std::cout << "Int to fixed constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
	setRawBits(floatValue);
	value = static_cast<int>(roundf(floatValue * (1 << fractBitsNum)));
	// std::cout << "Float to fixed constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		value = other.value;
	}
	// std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::fixedToFloat(void) const
{
	return (static_cast<float>(this->getRawBits())
		/ static_cast<float>(1 << fractBitsNum));
}

int Fixed::floatToFixed(const float floatValue) const
{
	return (static_cast<int>(roundf(floatValue
		* static_cast<float>(1 << fractBitsNum))));
}

int Fixed::fixedToInt(void) const
{
	return (this->getRawBits() >> fractBitsNum);
}

int Fixed::intToFixed(const int intValue) const
{
	return (intValue << fractBitsNum);
}

int Fixed::fractionPart(void) const
{
	return (this->getRawBits() & fractionMask);
}

int Fixed::wholePart(void) const
{
	return (this->getRawBits() & wholeMask);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.fixedToFloat();
	return o;
}

bool Fixed::operator>(const Fixed& rhs)
{
	return (this->value > rhs.value);
}

bool Fixed::operator<(const Fixed& rhs)
{
	return (this->value < rhs.value);
}

bool Fixed::operator>=(const Fixed& rhs)
{
	return (this->value >= rhs.value);
}

bool Fixed::operator<=(const Fixed& rhs)
{
	return (this->value <= rhs.value);
}

bool Fixed::operator==(const Fixed& rhs)
{
	return (this->value == rhs.value);
}

bool Fixed::operator!=(const Fixed& rhs)
{
	return (this->value != rhs.value);
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed resFixed;

	resFixed.value = this->value + other.value;
	return (resFixed);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed resFixed;

	resFixed.value = this->value - other.value;
	return (resFixed);
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed resFixed;
	
	resFixed.value = static_cast<int>((static_cast<long long>(this->value)
		* static_cast<long long>(other.value)) >> (fractBitsNum));
	return (resFixed);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed resFixed;
	resFixed.value = static_cast<int>((static_cast<long long>(this->value)
		<< fractBitsNum) / static_cast<long long>(other.value));
	return (resFixed);
}

Fixed Fixed::operator++()
{
	(this->value)++;
	return *this;
}

Fixed Fixed::operator--()
{
	(this->value)--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(this->value);
	return tmp; 
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(this->value);
	return tmp; 
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	// std::cout << "non-constant min invoked" << std::endl;
	return (a.value > b.value) ? b : a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	// std::cout << "constant min invoked" << std::endl;
	return (a.value > b.value) ? b : a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	// std::cout << "non-constant max invoked" << std::endl;
	return (a.value > b.value) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	// std::cout << "constant max invoked" << std::endl;
	return (a.value > b.value) ? a : b;
}