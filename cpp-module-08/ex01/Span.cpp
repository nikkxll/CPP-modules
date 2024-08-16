/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:41 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/16 12:29:51 by dnikifor         ###   ########.fr       */
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

int Span::shortestSpan()
{
	if (_set.size() < 2)
	{
		throw std::runtime_error("Not enough elements to calculate a span");
	}
	
	int minSpan = std::numeric_limits<int>::max();
	std::set<int>::const_iterator prev = _set.begin();
	std::set<int>::const_iterator curr = ++_set.begin();

	while (curr != _set.end())
	{
		int currSpan = *curr - *prev;
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

int Span::longestSpan()
{
	if (_set.size() < 2)
	{
		throw std::runtime_error("Not enough elements to calculate a span");
	}

	return *(_set.end()) - *(_set.begin());
}

std::set<int>& Span::getSet()
{
	return _set;
}
