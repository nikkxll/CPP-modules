/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/11 22:02:06 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {
    // log("Default constructor called");
}

Bureaucrat::Bureaucrat(const std::string name, size_t grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
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

const std::string Bureaucrat::getName() {
    return this->_name;
}

size_t Bureaucrat::getGrade() {
    return this->_grade;
}

void Bureaucrat::incrGrade() {
    if (_grade == 1) {
        throw GradeTooHighException();
    }
    _grade -= 1;
    log("Increased grade for " + getName() + " to " + std::to_string(getGrade()));
}

void Bureaucrat::decrGrade() {
    if (_grade == 150) {
        throw GradeTooLowException();
    }
    _grade += 1;
    log("Decreased grade for " + getName() + " to " + std::to_string(getGrade()));
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade is too low!";
}

void Bureaucrat::log(const std::string& message) const {
    std::cout << message << std::endl;
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << std::to_string(bureaucrat.getGrade()) << std::endl;
	return (stream);
}
