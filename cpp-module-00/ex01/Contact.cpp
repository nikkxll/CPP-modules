/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:13:59 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 15:43:54 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setDetails(const std::string& firstName,
	const std::string& lastName, const std::string& nickname,
	const std::string& phoneNumber, const std::string& darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void	Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|";
	printField(_firstName);
	printField(_lastName);
	printField(_nickname);
	std::cout << std::endl;
}

void	Contact::displayDetails() const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

void	Contact::printField(const std::string& field) const
{
	if (field.length() > 10)
		std::cout << std::setw(10) << field.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << field << "|";
}
