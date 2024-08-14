/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:11:16 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/14 18:50:31 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : array(nullptr), length(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : length(n)
{
	array = new T[length];
}

template<typename T>
Array<T>::Array(const Array& other) : length(other.length)
{
	array = new T[length];
	for (size_t i = 0; i < length; ++i)
		array[i] = other.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] array;
		length = other.length;
		array = new T[length];
		for (size_t i = 0; i < length; ++i)
			array[i] = other.array[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] array;
}

template<typename T>
size_t Array<T>::size() const
{
	return length;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= length || index < 0)
		throw std::out_of_range("Index out of range");
	return array[index];
}
