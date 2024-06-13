/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 16:31:45 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {
	// log("Default constructor called");
}

Bureaucrat::Bureaucrat(const std::string name, size_t grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
	// log("Overloaded constructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	// log("Copy constructor called");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	// log("Copy assignment operator called");
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	// log("Destructor called");
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

size_t Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrGrade() {
	if (_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade -= 1;
	log("Increased grade for " + getName() + " to " + std::to_string(getGrade()));
}

void Bureaucrat::decrGrade() {
	if (_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade += 1;
	log("Decreased grade for " + getName() + " to " + std::to_string(getGrade()));
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn`t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn`t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high for the bureaucrat!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low for the bureaucrat!";
}

void log(const std::string& message) {
	std::cout << message << std::endl;
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << std::to_string(bureaucrat.getGrade()) << std::endl;
	return (stream);
}
