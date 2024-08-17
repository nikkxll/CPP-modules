/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:44 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/17 12:51:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <limits>
#include <stdexcept>
#include <iostream>

class Span {
	private:
		std::set<int>	_set;
		unsigned int	_limit;
		
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
		void			addNumbers(InputIterator begin, InputIterator end);

		std::set<int>&	getSet();
		unsigned int	getLimit();
};

#include <Span.tpp>