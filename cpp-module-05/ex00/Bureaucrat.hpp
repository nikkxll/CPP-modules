/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:30 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/04 14:47:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat {
	private:
		const std::string name;
		size_t grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string, size_t);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();
	
		const std::string getName();
		size_t getGrade();
		void incrGrade(size_t grade);
		void decrGrade(size_t grade);

		class GradeTooHighException : public std::exception {
			public:
			const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
		};
};