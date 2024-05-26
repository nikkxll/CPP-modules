/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:30:23 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/26 20:50:25 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    std::cout << "Overloaded constructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.getX()), y(other.getY())
{
    std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other) {}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Point::~Point()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}