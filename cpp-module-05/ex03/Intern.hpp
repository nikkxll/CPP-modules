/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:24:59 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 16:25:13 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		std::string formNames[3];
		AForm* (*formCreators[3])(const std::string& target);

		static AForm* createPresidentialPardonForm(const std::string& target);
		static AForm* createRobotomyRequestForm(const std::string& target);
		static AForm* createShrubberyCreationForm(const std::string& target);

	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

		AForm* makeForm(const std::string name, const std::string target);
};