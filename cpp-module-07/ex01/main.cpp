/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/15 13:03:17 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "iter.hpp"

void square(int& elem)
{
	elem = elem * elem;
	std::cout << elem << " " << std::endl;
}

void foo(const int& elem)
{
	std::cout << elem << " " << std::endl;
}

void foo(std::string& elem)
{
	std::cout << elem << " " << std::endl;
}

int main()
{
	const int arr[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(arr) / sizeof(arr[0]);

	iter(arr, length, foo);

	std::string strArr[] = {"Hello", "World", "!"};
	size_t strLength = sizeof(strArr) / sizeof(strArr[0]);

	iter(strArr, strLength, foo);
	
	int arr1[] = {6, 7, 8, 9, 10};

	const size_t constLength = 5;

	iter(arr1, constLength, square);
}
