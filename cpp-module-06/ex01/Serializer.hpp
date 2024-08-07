/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:32:44 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/07 11:34:33 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include "data.h"

class Serializer {
	private:

	public:
		Serializer() = delete;
		Serializer(const Serializer&) = delete;
		Serializer& operator=(const Serializer&) = delete;
		~Serializer() = delete;

		static Data* deserialize(uintptr_t raw);
		static uintptr_t serialize(Data* ptr);
};