/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:13:59 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 14:30:55 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setDetails(const std::string& firstName,
	const std::string& lastName, const std::string& nickname,
	const std::string& phoneNumber, const std::string& darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void	Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|";
	printField(firstName);
	printField(lastName);
	printField(nickname);
	std::cout << std::endl;
}

void	Contact::displayDetails() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void	Contact::printField(const std::string& field) const
{
	if (field.length() > 10)
		std::cout << std::setw(10) << field.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << field << "|";
}
