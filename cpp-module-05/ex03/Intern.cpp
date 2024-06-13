/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:25:01 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 16:25:36 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	formNames[0] = "ShrubberyCreationForm";
	formCreators[0] = createShrubberyCreationForm;

	formNames[1] = "RobotomyRequestForm";
	formCreators[1] = createRobotomyRequestForm;

	formNames[2] = "PresidentialPardonForm";
	formCreators[2] = createPresidentialPardonForm;
	// std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	for (int i = 0; i < 3; ++i) {
		formNames[i] = other.formNames[i];
		formCreators[i] = other.formCreators[i];
	}
	// std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		for (int i = 0; i < 3; ++i) {
			formNames[i] = other.formNames[i];
			formCreators[i] = other.formCreators[i];
		}
	}
	// std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	// std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	for (int i = 0; i < 3; ++i) {
		if (formNames[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Error: Form " << name << " does not exist" << std::endl;
	return nullptr;
}