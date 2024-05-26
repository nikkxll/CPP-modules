/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:27:51 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/26 20:26:09 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.3333333333f ) * Fixed( 2 ) );
	Fixed c( Fixed( 1242.321f ) / Fixed( 31 ) );
	Fixed d( 55.22f );
	Fixed e( Fixed( 5.3333333333f ) * Fixed( 2 ) );
	Fixed const f(0.5f);
	
	std::cout << "Init a value: " << a << std::endl;
	std::cout << "Init b value: " << b << std::endl;
	std::cout << "Init c value: " << c << std::endl;
	std::cout << "Init d value: " << d << std::endl;
	
	std::cout << "a value after prefix: " << ++a << std::endl;
	std::cout << "a value during postfix: " << a++ << std::endl;
	std::cout << "a value after postfix: " << a << std::endl;
	std::cout << e << " + " << b << " = " << e + b << std::endl;
	std::cout << e << " - " << b << " = " << e - b << std::endl;
	std::cout << c << " * " << d << " = " << c * d << std::endl;
	std::cout << d << " / " << f << " = " << d / f << std::endl;

	Fixed& minAB = Fixed::min( a, c );
	const Fixed& constMinAB = Fixed::min( a, b );
	std::cout << "between " << a << " and " << c << " smaller :" << minAB << std::endl;
	std::cout << "between " << a << " and " << b << " smaller :" << constMinAB << std::endl;
	
	Fixed& maxAB = Fixed::max( d, c );
	const Fixed& constMaxAB = Fixed::max( a, f );
	std::cout << "between " << d << " and " << c << " greater :" << maxAB << std::endl;
	std::cout << "between " << a << " and " << f << " greater :" << constMaxAB << std::endl;
	
	return 0;
}