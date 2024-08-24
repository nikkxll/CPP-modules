/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/24 23:50:18 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>

class PmergeMe {
    private:
        static std::vector<int> _vectorA;
        static std::vector<int> _vectorB;
		static double _vector_struggler;

		PmergeMe() = delete;
		PmergeMe(const PmergeMe &) = delete;
		PmergeMe& operator=(const PmergeMe &) = delete;
		~PmergeMe() = delete;
    public:
        static void runVector(int argc, char *argv[]);
		static void initVectors(int argc, char *argv[]);
		static void isStrugglerInVector(std::vector<int>& fullVector);
		static void createVectors(std::vector<int>& fullVector);
		static int getJacobsthal(int n);
		static void insertionSortVectors(std::vector<int>& vectorA, std::vector<int>& vectorB);
		static void mergeInsertionVectors(std::vector<int>& vectorA, const std::vector<int>& vectorB);
		static void insertElement(std::vector<int>& vectorA, int element);
};