/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:57:09 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 19:17:41 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", false, 72, 45), _target("unknown")
{
	std::srand(std::time(nullptr));
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
	std::srand(std::time(nullptr));
	// std::cout << "RobotomyRequestForm overloaded constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("RobotomyRequestForm", false, 72, 45), _target(other._target)
{
	std::srand(std::time(nullptr));
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {}
	// std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (this->checkRequirments(executor)) {
		std::cout << "Bzzzzzzz... Bzzzzzzz..." << std::endl;

		if (std::rand() % 2) {
			std::cout << this->_target << " has been robotomized successfully!" << std::endl;
		} else {
			std::cout << "Robotomy of " << this->_target << " failed." << std::endl;
		}
	}
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}