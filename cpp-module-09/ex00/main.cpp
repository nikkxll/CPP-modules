/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/20 12:13:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(void)
{
    try {
        BitcoinExchange::csvReader("data.csv");
         for (const auto& entry : BitcoinExchange::_bitcoinPrices)
             std::cout << "Date: " << entry.first << ", Price: " << entry.second << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
