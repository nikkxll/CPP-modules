/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:01:26 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 18:36:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signed(false), _signGrade(150), _execGrade(150) {
	// log("Default constructor called");
}

AForm::AForm(const std::string name, bool isSigned, size_t signGrade, size_t execGrade)
	: _name(name), _signed(isSigned), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1) {
		throw AForm::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150) {
		throw AForm::GradeTooLowException();
	}
	// log("Overloaded constructor called");
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	// log("Copy constructor called");
}

AForm& AForm::operator=(const AForm& other) {
	// log("Copy assignment operator called");
	if (this != &other) {
		this->_signed = other._signed;
		this->_signGrade = other._signGrade;
		this->_execGrade = other._execGrade;
	}
	return *this;
}

AForm::~AForm() {
	// log("Destructor called");
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
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

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSignStatus() const {
	return this->_signed;
}

size_t AForm::getSignGrade() const {
	return this->_signGrade;
}

size_t AForm::getExecGrade() const {
	return this->_execGrade;
}

bool AForm::checkRequirments(const Bureaucrat& bureaucrat) const {
	if (bureaucrat.getGrade() > this->getExecGrade())
	{
		throw Bureaucrat::GradeTooLowException();
		return false;
	}
	else if (this->getSignStatus() == false)
	{
		throw AForm::NotSignedFormException();
		return false;
	}
	return true;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high for the form!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low for the form!";
}

const char* AForm::NotSignedFormException::what() const noexcept {
	return "Form is not signed yet!";
}

std::ostream& operator<<(std::ostream& stream, AForm& form) {
	stream << form.getName() << ", form signed grade " << form.getSignGrade() << ", form exec grade ";
	stream << form.getExecGrade() << ". Is form signed: " << form.getSignStatus() << std::endl;
	return (stream);
}
