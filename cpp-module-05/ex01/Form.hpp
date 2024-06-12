/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:01:24 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 13:25:13 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		size_t _signGrade;
		size_t _execGrade;

	public:
		Form();
		Form(const std::string, bool, size_t, size_t);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();

		void beSigned(Bureaucrat& bureaucrat);
		const std::string getName();
		bool getSignStatus();
		size_t getSignGrade();
		size_t getExecGrade();

		class GradeTooHighException : public std::exception {
			public:
			const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& stream, Form& form);