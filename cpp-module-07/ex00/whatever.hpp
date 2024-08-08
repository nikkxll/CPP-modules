/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:54:53 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/08 12:58:05 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& minCustom(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T& maxCustom(const T& a, const T& b)
{
    return (a > b) ? a : b;
}