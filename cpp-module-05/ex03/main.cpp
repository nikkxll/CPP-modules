/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:32 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 16:38:01 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Intern intern;
	Bureaucrat max("max",40);
	Bureaucrat superhuman("superhuman",1);

	AForm* form1 = intern.makeForm("RobotomyRequestForm", "Bender");
	if (form1) {
		try {
			max.signForm(*form1);
			max.executeForm(*form1);
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		} catch (const AForm::NotSignedFormException& e) {
			std::cout << e.what() << std::endl;
		}
		delete form1;
	}

	std::cout << std::endl;
	
	AForm* form2 = intern.makeForm("PresidentialPardonForm", "Max Smith");
	if (form2) {
		try {
			superhuman.signForm(*form2);
			max.signForm(*form2);
			superhuman.executeForm(*form2);
			max.executeForm(*form2);
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		} catch (const AForm::NotSignedFormException& e) {
			std::cout << e.what() << std::endl;
		}
		delete form2;
	}

	std::cout << std::endl;

	AForm* form3 = intern.makeForm("ShrubberyCreationForm", "rubb");
	if (form3) {
		try {
			max.signForm(*form3);
			max.executeForm(*form3);
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		} catch (const AForm::NotSignedFormException& e) {
			std::cout << e.what() << std::endl;
		}
		delete form2;
	}

	std::cout << std::endl;
	
	AForm* form4 = intern.makeForm("SomeOtherWeirdForm", "Nobody");
	if (form4) {
		delete form4;
	}
	return 0;
}