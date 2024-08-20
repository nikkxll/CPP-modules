/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:52:39 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/20 12:13:01 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <iostream>
#include <map>

class BitcoinExchange {
    private:
    public:
        static std::map<std::string, double> _bitcoinPrices;
        static void csvReader(const std::string& filePath);
        
        static void isValidPath(std::ifstream& file, const std::string& filePath);
        static bool isLeapYear(int year);
        static void isValidDate(int year, int month, int day);
};