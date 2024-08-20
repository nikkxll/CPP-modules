/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:19:08 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/20 12:13:13 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

std::map<std::string, double> BitcoinExchange::_bitcoinPrices;

void BitcoinExchange::isValidPath(std::ifstream& file, const std::string& filePath)
{
    if (!file.is_open())
        throw std::runtime_error("Error: Cannot open the file " + filePath);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::isValidDate(int year, int month, int day)
{
    if (day < 1)
        throw std::runtime_error("Wrong 'day' format");

    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return ;
        case 4: case 6: case 9: case 11:
            return ;
        case 2:
            if (isLeapYear(year))
                return ;
            else
                return ;
        default:
            throw std::runtime_error("Wrong 'day' format");
    }
}

void BitcoinExchange::csvReader(const std::string& filePath)
{
    std::ifstream file(filePath);
    std::string line;
    std::regex rowPattern(R"(^(\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01]),([0-9]{1,9}(?:\.[0-9]+)?)\s*$)");

    try {
        isValidPath(file, filePath);
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    while (std::getline(file, line))
    {
        std::smatch matches;

        if (std::regex_match(line, matches, rowPattern))
        {
            int year = std::stoi(matches[1].str());
            int month = std::stoi(matches[2].str());
            int day = std::stoi(matches[3].str());

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
