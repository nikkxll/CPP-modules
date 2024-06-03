/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:10:39 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/03 16:35:53 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal() = 0;

		std::string getType() const;
		virtual void makeSound() const = 0;
		virtual const std::string* getIdeas() const = 0;
		virtual std::string getIdea(int pos) const = 0;
		virtual void setIdea(int pos, std::string idea) = 0;
};