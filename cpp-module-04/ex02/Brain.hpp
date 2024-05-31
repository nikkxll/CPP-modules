/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:48:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/31 11:56:26 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define IDEAS_SIZE 100

class Brain {
	private:
		std::string ideas[IDEAS_SIZE];
		
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		const std::string* getIdeas() const;
		std::string getIdea(int pos) const;
		void setIdea(int pos, std::string idea);
};