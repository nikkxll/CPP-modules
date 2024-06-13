/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:39:41 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 17:09:09 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", false, 145, 137), _target("unknown")
{
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm overloaded constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreationForm", false, 145, 137), _target(other._target)
{
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {}
	// std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outFile(filename);

	if (!outFile) {
		std::cout << "Error creating file: " << filename << std::endl;
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		outFile << R"(
		4
	   242
	  42424
	 2424242
	424242424
		H
	   IVE
	  HIVEH
	 IVEHIVE
	HIVEHIVEH
   IVEHIVEHIVE
  HIVEHIVEHIVEH
 IVEHIVEHIVEHIVE
        I)" << std::endl;
	}
	
	outFile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (this->checkRequirments(executor)) {
		executeAction();
	}
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}