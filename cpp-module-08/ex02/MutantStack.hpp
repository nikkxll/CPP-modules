/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:15:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/19 14:16:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:

	using iterator = typename Container::iterator;
	using const_iterator = typename Container::const_iterator;
	
	MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	MutantStack& operator=(const MutantStack& other) = default;
	~MutantStack() = default;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include <MutantStack.tpp>