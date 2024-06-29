/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:39:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/06/29 23:57:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isInteger(const std::string& str)
{
    std::regex intRegex(R"(^[-+]?\d+$)");
    return std::regex_match(str, intRegex);
}

bool ScalarConverter::isFloat(const std::string& str)
{
    std::regex floatRegex(R"(^[-+]?\d+\.\d{1}f$)");
    return std::regex_match(str, floatRegex);
}

bool ScalarConverter::isDouble(const std::string& str)
{
    std::regex doubleRegex(R"(^[-+]?\d+\.\d{1}$)");
    return std::regex_match(str, doubleRegex);
}

bool ScalarConverter::isChar(const std::string& str)
{
    std::regex charRegex(R"(^'[\x20-\x7E]'$)");
    return std::regex_match(str, charRegex);
}
