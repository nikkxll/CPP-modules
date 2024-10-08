/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:30 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/11 21:56:49 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		size_t _grade;
		void log(const std::string& message) const;

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

		class GradeTooHighException : public std::exception {
			public:
			const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat& bureaucrat);