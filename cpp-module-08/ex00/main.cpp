/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/15 22:52:51 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    try {
        std::vector<int> vec = {100, 2000, 14, 1234, 5000000};
        std::vector<int>::iterator vecIt = easyfind(vec, 1234);
        std::cout << "Found in vector: " << *vecIt << std::endl;
        std::cout << "Address of found position in the vec: " << &(vec[3]) << std::endl;
        std::cout << "Iterator address: " << &(*vecIt) << std::endl << std::endl;

        std::deque<int> deq = {7, 14, 2, 1, 1};
        std::deque<int>::iterator deqIt = easyfind(deq, 1);
        std::cout << "Found in deque: " << *deqIt << std::endl;
        std::cout << "Address of found position in the deque: " << &(deq[3]) << std::endl;
        std::cout << "Iterator address: " << &(*deqIt) << std::endl << std::endl;

        const std::vector<int> constVec = {-1, 0, 3, 4, 5};
        const std::vector<int>::const_iterator constVecIt = easyfind(constVec, 0);
        std::cout << "Found in const vector: " << *constVecIt << std::endl << std::endl;

        std::list<int> lst = {10, 0, 30};
        std::list<int>::iterator listIt = easyfind(lst, 20);
        std::cout << "Found in list: " << *listIt << std::endl << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
