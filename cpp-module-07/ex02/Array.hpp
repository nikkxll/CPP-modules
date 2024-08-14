/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:51:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/14 18:29:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
class Array {
	private:
		T*		array;
		size_t	length;

	public:
		Array();
		Array(unsigned int);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();
		T& operator[](size_t index);

		size_t	size() const;
};

#include "Array.tpp"