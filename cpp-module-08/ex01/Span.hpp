/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:44 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/20 12:16:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <vector>
#include <limits>
#include <stdexcept>
#include <algorithm>

class Span {
	private:
		std::set<int>	_set;
		unsigned int	_limit;
		bool			_isEven = false;
		
	public:
		Span() = delete;
		Span(unsigned int);
		Span(const Span &);
		Span& operator=(const Span &);
		~Span();

		long			shortestSpan();
		long			longestSpan();
		void			addNumber(int);
		
		template <typename InputIterator>
		void			addNumbers(InputIterator begin, InputIterator end)
		{
			std::vector<int> tempContainer;
			
			if (std::distance(begin, end) + _set.size() > _limit)
				throw std::out_of_range("Adding this range would exceed set's capacity");

			tempContainer.insert(tempContainer.end(), _set.begin(), _set.end());
			tempContainer.insert(tempContainer.end(), begin, end);
			std::sort(tempContainer.begin(), tempContainer.end());

			if (std::unique(tempContainer.begin(), tempContainer.end()) != tempContainer.end())
				_isEven = true;

			_set.insert(begin, end);
		}

		std::set<int>&	getSet();
		unsigned int	getLimit();
};