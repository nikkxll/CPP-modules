/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:27:51 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/27 11:38:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

// https://www.desmos.com/calculator/bi14xz1jci

int main(void)
{
	Point a( -8, 0 );
	Point b( 8, 0 );
	Point c( 0, 10 );
	Point point( -1, 3 );
	
	if (bsp(a,b,c,point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside of the triangle" << std::endl;
		
	return 0;
}
