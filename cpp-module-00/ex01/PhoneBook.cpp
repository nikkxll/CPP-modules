/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:56:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 21:10:14 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::printErrorMessage(std::string message) const {
	std::cerr << RED << message << EC << std::endl;
}

void	PhoneBook::printMessage(std::string message) const {
	std::cout << GREEN << message << EC << std::endl;
}

void	PhoneBook::addContact() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		this->printErrorMessage("All fields must be filled. Contact not added.");
		return;
	}

	contacts[_nextIndex].setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_nextIndex = (_nextIndex + 1) % MAX_CONTACTS;
	if (_count < MAX_CONTACTS)
		_count++;
	this->printMessage("Added!");
}

void	PhoneBook::searchContacts() const {
	if (_count == 0)
	{
		this->printErrorMessage("The phonebook is empty.");
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < _count; ++i)
		contacts[i].displaySummary(i);

	int index;
	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;
	if(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		this->printErrorMessage("Input is in a wrong format.");
		return;
	}

	if (index < 0 || index >= _count)
		this->printErrorMessage("Invalid index.");
	else
		contacts[index].displayDetails();
	std::cin.ignore(INT_MAX, '\n');
}

void	PhoneBook::start() {
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			this->addContact();
		else if (command == "SEARCH")
			this->searchContacts();
		else if (command == "EXIT")
		{
			this->printMessage("See you!");
			break;
		}
		else
			this->printErrorMessage("Invalid command.");
	}
}
