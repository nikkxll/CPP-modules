/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:24:59 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/13 00:03:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using Form = AForm;

class Intern {
	private:

	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

        Form* makeForm(const std::string name, const std::string target);
};