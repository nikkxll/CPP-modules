/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:01:26 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 17:10:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unknown"), _signed(false), _signGrade(150), _execGrade(150) {
	// log("Default constructor called");
}

Form::Form(const std::string name, bool isSigned, size_t signGrade, size_t execGrade)
	: _name(name), _signed(isSigned), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw Form::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw Form::GradeTooLowException();
	}
	// log("Overloaded constructor called");
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	// log("Copy constructor called");
}

Form& Form::operator=(const Form& other) {
	// log("Copy assignment operator called");
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
	// log("Destructor called");
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->_signed == false) {
		this->_signed = true;
		log(bureaucrat.getName() + " signed " + this->getName());
	}
	else {
		std::cout << this->getName() << " form has been already signed" << std::endl;
	}
}

const std::string Form::getName() {
	return this->_name;
}

bool Form::getSignStatus() {
	return this->_signed;
}

size_t Form::getSignGrade() {
	return this->_signGrade;
}

size_t Form::getExecGrade() {
	return this->_execGrade;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high for the form!";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low for the form!";
}

std::ostream& operator<<(std::ostream& stream, Form& form) {
	stream << form.getName() << ", form signed grade " << form.getSignGrade() << ", form exec grade ";
	stream << form.getExecGrade() << ". Is form signed: " << form.getSignStatus() << std::endl;
	return (stream);
}
