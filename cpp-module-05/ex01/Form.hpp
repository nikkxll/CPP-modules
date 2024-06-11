/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:01:24 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/11 22:11:51 by dnikifor         ###   ########.fr       */
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
};