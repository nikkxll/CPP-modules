/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:30 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 17:56:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		size_t _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string, size_t);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();
	
		const std::string getName();
		size_t getGrade();
		void incrGrade();
		void decrGrade();
		void signForm(Form& form);

		class GradeTooHighException : public std::exception {
			public:
			const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
		};
};

void log(const std::string& message);
std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat);