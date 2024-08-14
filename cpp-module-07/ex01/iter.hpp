/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:54:53 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/14 16:53:06 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>
void iter(T* arr, const size_t length, void (*foo)(T&))
{
	for (size_t i = 0; i < length; ++i)
		foo(arr[i]);
}

template <typename T>
void iter(const T* arr, const size_t length, void (*foo)(const T&))
{
	for (size_t i = 0; i < length; ++i)
		foo(arr[i]);
}
