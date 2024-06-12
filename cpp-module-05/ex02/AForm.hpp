/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:01:24 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/12 18:36:45 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		size_t _signGrade;
		size_t _execGrade;

	public:
		AForm();
		AForm(const std::string, bool, size_t, size_t);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm() = 0;

		void beSigned(Bureaucrat& bureaucrat);
		const std::string getName() const;
		bool getSignStatus() const;
		size_t getSignGrade() const;
		size_t getExecGrade() const;
		bool checkRequirments(const Bureaucrat& bureaucrat) const;

		virtual void execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
			const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
		};
		class NotSignedFormException : public std::exception {
		public:
			const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& stream, AForm& form);