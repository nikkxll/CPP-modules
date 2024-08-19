/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/19 14:33:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>
#include <random>
#include <iostream>

void first_test();
void second_test();
void third_test();
void fourth_test();
void fifth_test();

int main(void)
{
	first_test();
	second_test();
	third_test();
	fourth_test();
	fifth_test();
}

void first_test()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void second_test()
{
	int range = 1000000;
	Span sp(range);

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	std::vector<int> randomNumbers(range);
	std::generate(randomNumbers.begin(), randomNumbers.end(), [&]() { return dist(rng); });

	sp.addNumbers(randomNumbers.begin(), randomNumbers.end());

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void third_test()
{
	try {
		Span sp = Span(2);
		sp.addNumber(1);
		sp.addNumber(1000);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}

void fourth_test()
{
	{
		try {
			Span sp = Span(0);
			sp.addNumber(1);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::out_of_range &e) {
			std::cout << e.what() << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Span sp = Span(2);
			sp.addNumber(1);
			sp.addNumber(1);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::out_of_range &e) {
			std::cout << e.what() << std::endl;
		} catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void fifth_test()
{
	try {
		std::vector<int> vec;
		Span sp = Span(10);
		for ( int i = 1; i <= 10; i++ ) vec.push_back(i);
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}