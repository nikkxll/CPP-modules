/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:56:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/20 14:42:02 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::printMessage(std::string message, std::string color) const {
	std::cout << color << message << EC << std::endl;
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
		this->printMessage("All fields must be filled. Contact not added.", RED);
		return;
	}

	contacts[nextIndex].setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;
	if (count < MAX_CONTACTS)
		count++;
	this->printMessage("Added!", GREEN);
}

void	PhoneBook::searchContacts() const {
	if (count == 0)
	{
		this->printMessage("The phonebook is empty.", RED);
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < count; ++i)
		contacts[i].displaySummary(i);

	int index;
	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;
	if(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		this->printMessage("Input is in a wrong format.", RED);
		return;
	}

	if (index < 0 || index >= count)
		this->printMessage("Invalid index.", RED);
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
			this->printMessage("See you!", GREEN);
			break;
		}
		else
			this->printMessage("Invalid command.", RED);
	}
}
