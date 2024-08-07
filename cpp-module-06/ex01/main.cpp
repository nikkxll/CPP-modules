/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:31:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/07 13:02:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.h"
#include <iostream>

int main()
{
	// Serializer serializer;
	
	Data originalData(42, "Hive Helsinki Coding School");

	std::cout << "originalData address: " << &originalData << std::endl;

	uintptr_t raw = Serializer::serialize(&originalData);

	std::cout << "castedData address: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "deserializedData address: " << deserializedData << std::endl;

	if (deserializedData == &originalData)
		std::cout << "Match" << std::endl;
	else
		std::cout << "Dismatch" << std::endl;

	std::cout << "Original Data: " << originalData.number << ", " << originalData.text << std::endl;
	std::cout << "Deserialized Data: " << deserializedData->number << ", " << deserializedData->text << std::endl;

	return 0;
}
