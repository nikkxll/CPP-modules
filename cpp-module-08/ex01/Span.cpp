/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:41 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/19 14:32:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

Span::Span(unsigned int N) : _limit(N) {}

Span::Span(const Span &other) : _set(other._set), _limit(other._limit) {}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_set = other._set;
		_limit = other._limit;
	}
	return *this;
}

Span::~Span() {}

long Span::shortestSpan()
{
	if (_isEven == true)
	{
		return 0;
	}

	if (_set.size() < 2)
	{
		throw std::runtime_error("Not enough elements to calculate a span");
	}

	long minSpan = std::numeric_limits<int>::max();
	std::set<int>::const_iterator prev = _set.begin();
	std::set<int>::const_iterator curr = ++_set.begin();

	while (curr != _set.end())
	{
		long currSpan = static_cast<long>(*curr) - static_cast<long>(*prev);
		if (currSpan < minSpan)
			minSpan = currSpan;
		prev = curr;
		++curr;
	}

	return minSpan;
}

void Span::addNumber(int number)
{
	if (_set.size() == _limit)
	{
		throw std::out_of_range("Adding this range would exceed set's capacity");
	}
	if (_set.find(number) != _set.end())
	{
		_isEven = true;
	}
	_set.insert(number);
}

long Span::longestSpan()
{
	if (_set.size() < 1)
	{
		throw std::runtime_error("Not enough elements to calculate a span");
	}
	return static_cast<long>(*(_set.rbegin())) - static_cast<long>(*(_set.begin()));
}

std::set<int>& Span::getSet()
{
	return _set;
}

unsigned int Span::getLimit()
{
	return _limit;
}
