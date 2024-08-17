/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:41 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/17 12:54:38 by dnikifor         ###   ########.fr       */
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
		throw std::runtime_error("Set is already full");
	}
	_set.insert(number);
}

long Span::longestSpan()
{
	if (_set.size() < 2)
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
