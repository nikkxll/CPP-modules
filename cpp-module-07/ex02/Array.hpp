/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:51:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/15 13:11:59 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
class Array {
	private:
		T*		_array;
		size_t	_length;

	public:
		Array();
		Array(unsigned int);
		Array(const Array<T>&);
		Array<T>& operator=(const Array<T>&);
		~Array();
		T& operator[](size_t);
		const T& operator[](size_t) const;

		size_t	size() const;
};

#include "Array.tpp"