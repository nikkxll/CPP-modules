/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:44 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/16 12:21:10 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <limits>
#include <stdexcept>

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

		int				shortestSpan();
		int				longestSpan();
		void			addNumber(int);

		std::set<int>&	getSet();
};