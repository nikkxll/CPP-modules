/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:30:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/26 20:50:07 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

#endif