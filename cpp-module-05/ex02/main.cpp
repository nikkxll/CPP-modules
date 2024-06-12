/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:32 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 20:38:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat max("Max", 90);
	Bureaucrat superhuman("unnamed", 1);
	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("home");
	RobotomyRequestForm robotomy = RobotomyRequestForm("R2-D2");
	PresidentialPardonForm pardon = PresidentialPardonForm("max");
	std::cout << max;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	
	std::cout << std::endl;

	try {
		max.executeForm(shrubbery);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const AForm::NotSignedFormException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	std::cout << std::endl;

	try {
		shrubbery.beSigned(max);
		max.executeForm(shrubbery);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const AForm::NotSignedFormException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	std::cout << std::endl;

	try {
		robotomy.beSigned(max);
		max.executeForm(robotomy);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const AForm::NotSignedFormException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	std::cout << std::endl;
	
	try {
		robotomy.beSigned(superhuman);
		superhuman.executeForm(robotomy);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const AForm::NotSignedFormException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		pardon.beSigned(max);
		max.executeForm(pardon);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const AForm::NotSignedFormException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		pardon.beSigned(superhuman);
		superhuman.executeForm(pardon);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const AForm::NotSignedFormException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;
	
	return 0;
}