/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:52:39 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/21 19:29:46 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <iostream>
#include <map>
#include <iomanip>

class BitcoinExchange {
	private:
		static std::map<std::string, double> _bitcoinPrices;

		static void databaseReader(const std::string& filePath);
		static void isValidPath(std::ifstream& file, const std::string& filePath);
		static bool isLeapYear(unsigned int year);
		static void isValidDate(unsigned int year, unsigned int month, unsigned int day);
		static void inputProcessing(const std::string& filePath);
		static void calculation(std::string& date, double amount);
		static void processLine(const std::string& line, const std::regex& pipePattern);
		static bool isValidAndFormattedDate(const std::string& dateStr, std::string& foundDate);
		static bool isValidAmount(const std::string& numberStr, double& amount);

	public:
		static void run(char *initFilePath);
};