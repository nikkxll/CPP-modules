/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:10:39 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/30 14:15:20 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
		virtual const std::string* getIdeas() const = 0;
		virtual std::string getIdea(int pos) const = 0;
		virtual void setIdea(int pos, std::string idea) = 0;
};