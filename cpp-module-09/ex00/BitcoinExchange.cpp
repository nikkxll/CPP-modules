/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:19:08 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/21 19:34:01 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

std::map<std::string, double> BitcoinExchange::_bitcoinPrices;

void BitcoinExchange::run(char *initFilePath)
{
	try {
		std::string filePath(initFilePath);
		BitcoinExchange::databaseReader("data.csv");
		BitcoinExchange::inputProcessing(filePath);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void BitcoinExchange::isValidPath(std::ifstream& file, const std::string& filePath)
{
	if (!file.is_open())
		throw std::runtime_error("Error: Cannot open the file " + filePath);
}

bool BitcoinExchange::isLeapYear(unsigned int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::isValidDate(unsigned int year, unsigned int month, unsigned int day)
{
	if (day < 1)
		throw std::runtime_error("Wrong day format (<1)");

	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				throw std::runtime_error("Wrong day format (>31)");
			break;
		case 4: case 6: case 9: case 11:
			if (day > 30)
				throw std::runtime_error("Wrong day format (>30)");
			break;
		case 2:
			if (isLeapYear(year)) {
				if (day > 29)
					throw std::runtime_error("Wrong day format (>29)");
			}
			else {
				if (day > 28)
					throw std::runtime_error("Wrong day format (>28)");
			}
			break;
		default:
			throw std::runtime_error("Wrong day format");
	}
}

void BitcoinExchange::databaseReader(const std::string& filePath)
{
	std::ifstream file(filePath);
	std::string line;
	std::regex rowPattern(R"(^(\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01]),([0-9]{1,9}(?:\.[0-9]+)?)\s*$)");

	try {
		isValidPath(file, filePath);
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	while (std::getline(file, line)) {
		std::smatch matches;

		if (std::regex_match(line, matches, rowPattern)) {
			unsigned int year = std::stoi(matches[1].str());
			unsigned int month = std::stoi(matches[2].str());
			unsigned int day = std::stoi(matches[3].str());

			try {
				isValidDate(year, month, day);
				std::string date = matches[1].str() + "-" + matches[2].str() + "-" + matches[3].str();
				double price = std::stod(matches[4].str());
				_bitcoinPrices[date] = price;
			}
			catch (std::runtime_error& e) {
				std::cout << e.what() << std::endl;
				std::cout << matches[1].str() << "-" << matches[2].str() << "-" << matches[3].str() << std::endl;
			}
		}
	}
}

void BitcoinExchange::calculation(std::string& date, double amount)
{
	auto it = --(_bitcoinPrices.upper_bound(date));
	double multiplier = date.compare((*_bitcoinPrices.begin()).first) < 0 ? 0 : (*it).second;
	std::cout << date << " => " << amount << " = " << std::fixed;
	std::cout << std::setprecision(2) << amount * multiplier << std::endl;
}

void BitcoinExchange::inputProcessing(const std::string& filePath)
{
	std::ifstream file(filePath);
	std::string line;
	std::regex pipePattern(R"(^[^|]*\|[^|]*$)");
	std::string firstLine;

	try {
		isValidPath(file, filePath);
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::getline(file, firstLine);
	if (firstLine != "date | value")
		throw std::runtime_error("Wrong header in input.txt");
	while (std::getline(file, line)) {
		processLine(line, pipePattern);
	}
}

void BitcoinExchange::processLine(const std::string& line, const std::regex& pipePattern)
{
	std::smatch matches;

	if (std::regex_match(line, pipePattern)) {
		std::size_t delimiterPos = line.find('|');
		std::string dateStr = line.substr(0, delimiterPos - 1);
		std::string numberStr = line.substr(delimiterPos + 2);
		std::string foundDate;
		double amount;

		if (isValidAndFormattedDate(dateStr, foundDate)) {
			if (isValidAmount(numberStr, amount)) {
				calculation(foundDate, amount);
			}
		}
	} else {
		std::cout << "Error: bad input => " << line << std::endl;
	}
}

bool BitcoinExchange::isValidAndFormattedDate(const std::string& dateStr, std::string& foundDate)
{
	std::regex datePattern(R"(^(\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)");
	std::smatch matches;

	if (std::regex_match(dateStr, matches, datePattern)) {
		unsigned int year = std::stoi(matches[1].str());
		unsigned int month = std::stoi(matches[2].str());
		unsigned int day = std::stoi(matches[3].str());

		try {
			isValidDate(year, month, day);
			foundDate = matches[1].str() + "-" + matches[2].str() + "-" + matches[3].str();
			return true;
		} catch (std::runtime_error& e) {
			std::cout << "Error: bad date => " << foundDate << std::endl;
		}
	} else {
		std::cout << "Error: invalid format" << std::endl;
	}

	return false;
}

bool BitcoinExchange::isValidAmount(const std::string& numberStr, double& amount)
{
	try {
		amount = std::stod(numberStr);
	} catch (std::exception& e) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	if (amount < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (amount > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}
