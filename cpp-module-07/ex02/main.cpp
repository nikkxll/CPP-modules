/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/15 18:33:31 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

struct Point
{
	std::string x;
	int y;

	Point& operator=(const Point& other)
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
		}
		return *this;
	}
};

int main(void)
{
	{
		Array<int> arr1;
		std::cout << "Size of arr1: " << arr1.size() << std::endl;

		const size_t size = 5;
		Array<int> arr2(size);
		
		for (size_t i = 0; i < size; ++i) {
			arr2[i] = static_cast<int>(i * 10);
		}

		std::cout << "Elements of arr2: ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;

		Array<int> arr3(arr2);
		std::cout << "Elements of arr3 (copied from arr2): ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr3[i] << " ";
		}
		std::cout << std::endl;

		Array<int> arr4;
		arr4 = arr2;
		std::cout << "Elements of arr4 (assigned from arr2): ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr4[i] << " ";
		}
		std::cout << std::endl;

		arr2[0] = 100;
		std::cout << "Elements of arr2 after modification: ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Elements of arr3 (should remain unchanged): ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr3[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Elements of arr4 (should remain unchanged): ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr4[i] << " ";
		}
		std::cout << std::endl;
	}

	{
		Array<Point> points(3);
		points[0] = {"first", 1};
		points[1] = {"secind", 2};
		points[2] = {"third", 3};

		for (size_t i = 0; i < points.size(); ++i) {
			std::cout << "Point " << i << ": (" << points[i].x << ", " << points[i].y << ")\n";
		}

		return 0;
	}

	return 0;
}
