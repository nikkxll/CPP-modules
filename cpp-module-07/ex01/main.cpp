/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/14 16:55:05 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void foo(T& elem)
{
	std::cout << elem << " ";
}

template <typename T>
void foo(const T& elem)
{
	std::cout << elem << " ";
}

int main()
{
	const int arr[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(arr) / sizeof(arr[0]);

	iter(arr, length, foo<int>);

	std::string strArr[] = {"Hello", "World", "!"};
	size_t strLength = sizeof(strArr) / sizeof(strArr[0]);

	iter(strArr, strLength, foo<std::string>);
}
