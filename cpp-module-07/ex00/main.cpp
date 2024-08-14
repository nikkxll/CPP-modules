/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/13 15:11:42 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
		std::cout << std::endl;
	}
	{
		bool left = true, right = false;
		int x = 10, y = 20;
		double a = 5.5, b = 2.2;
		std::string str1 = "apple", str2 = "orange";
		const std::string conststr1 = "banana", conststr2 = "pineapple";

		std::cout << "Original x: " << x << ", y: " << y << std::endl;
		swap(x, y);
		std::cout << "Swapped x: " << x << ", y: " << y << std::endl;

		std::cout << "Min of " << left << " and " << right << " is " << min(left, right) << std::endl;
		std::cout << "Max of " << left << " and " << right << " is " << max(left, right) << std::endl;

		std::cout << "Min of " << a << " and " << b << " is " << min(a, b) << std::endl;
		std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;

		std::cout << "Min of " << str1 << " and " << str2 << " is " << ::min(str1, str2) << std::endl;
		std::cout << "Max of " << str1 << " and " << str2 << " is " << ::max(str1, str2) << std::endl;

		std::cout << "Min of " << conststr1 << " and " << conststr2 << " is " << ::min(conststr1, conststr2) << std::endl;
		std::cout << "Max of " << conststr1 << " and " << conststr2 << " is " << ::max(conststr1, conststr2) << std::endl;
	}
}
