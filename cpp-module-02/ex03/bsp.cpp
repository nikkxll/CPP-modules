/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:30:19 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/27 11:38:25 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
    Fixed area = (a.getX()*(b.getY()-c.getY())
                + b.getX()*(c.getY()-a.getY())
                + c.getX()*(a.getY()-b.getY())) / 2;
    if (area < 0)
        area = area * (-1);
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
   
    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;

    if ((point.getX() == a.getX() && point.getY() == a.getY())
        || (point.getX() == b.getX() && point.getY() == b.getY())
        || (point.getX() == c.getX() && point.getY() == c.getY()))
        return false;

   return (A == A1 + A2 + A3);
}
