/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:11:16 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/15 13:11:56 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : _array(nullptr), _length(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _length(n)
{
	_array = new T[_length];
}

template<typename T>
Array<T>::Array(const Array& other) : _length(other._length)
{
	_array = new T[_length];
	for (size_t i = 0; i < _length; ++i)
		_array[i] = other._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		_length = other._length;
		_array = new T[_length];
		for (size_t i = 0; i < _length; ++i)
			_array[i] = other._array[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
size_t Array<T>::size() const
{
	return _length;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _length)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _length)
		throw std::out_of_range("Index out of range");
	return _array[index];
}
