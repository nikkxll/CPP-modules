/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:32 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 11:51:36 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat mike("Mike", 3);
		std::cout << mike;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Something went wrong: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat sam("Sam", 1);
		std::cout << sam;
		sam.incrGrade();
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Something went wrong: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat stranger;
		std::cout << stranger;
		stranger.decrGrade();
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Something went wrong: " << e.what() << std::endl;
	}
		
	std::cout << std::endl;

	try {
		Bureaucrat charlie("Charlie", 100);
		std::cout << charlie;
		charlie.incrGrade();
		std::cout << charlie;
		charlie.decrGrade();
		charlie.decrGrade();
		charlie.decrGrade();
		std::cout << charlie;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const std::exception& e) {
		std::cout << "Other exception: " << e.what() << '\n';
	}

	return 0;
}