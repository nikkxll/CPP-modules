/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/08 14:09:43 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	bool left = true, right = false;
	int x = 10, y = 20;
	double a = 5.5, b = 2.2;
	std::string str1 = "apple", str2 = "orange";
	const std::string conststr1 = "banana", conststr2 = "pineapple";

	std::cout << "Original x: " << x << ", y: " << y << std::endl;
	swap(x, y);
	std::cout << "Swapped x: " << x << ", y: " << y << std::endl;

	std::cout << "Min of " << left << " and " << right << " is " << minCustom(left, right) << std::endl;
	std::cout << "Max of " << left << " and " << right << " is " << maxCustom(left, right) << std::endl;

	std::cout << "Min of " << a << " and " << b << " is " << minCustom(a, b) << std::endl;
	std::cout << "Max of " << a << " and " << b << " is " << maxCustom(a, b) << std::endl;

	std::cout << "Min of " << str1 << " and " << str2 << " is " << minCustom(str1, str2) << std::endl;
	std::cout << "Max of " << str1 << " and " << str2 << " is " << maxCustom(str1, str2) << std::endl;

	std::cout << "Min of " << conststr1 << " and " << conststr2 << " is " << minCustom(conststr1, conststr2) << std::endl;
	std::cout << "Max of " << conststr1 << " and " << conststr2 << " is " << maxCustom(conststr1, conststr2) << std::endl;
	
	return 0;
}
