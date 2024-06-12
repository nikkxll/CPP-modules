/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:32 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 15:13:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat testOne("testBureaucrat", 0);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form testOne("testForm", false, 100, 200);
	} catch (const Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const Form::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	Bureaucrat bob("Bob", 140);
	Bureaucrat max("Max", 70);
	Bureaucrat alex("Alex", 149);
	Form formOne("Taxes", false, 100, 130);
	std::cout << bob;
	std::cout << max;
	std::cout << alex;
	std::cout << formOne;
	
	std::cout << std::endl;
	
	try {
		bob.signForm(formOne);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		alex.signForm(formOne);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		max.signForm(formOne);
		max.signForm(formOne);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	Form formTwo("Fees", false, 78, 100);
	Bureaucrat freddy;
	std::cout << freddy;
	std::cout << formTwo;
	
	freddy = max;
	std::cout << freddy;

	try {
		freddy.signForm(formTwo);
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	std::cout << formOne;
	std::cout << formTwo;

	return 0;
}