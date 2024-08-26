/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/26 10:54:50 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <iomanip>

using vector = std::vector<int>;

class PmergeMe {
    private:
        static vector _vectorA;
        static vector _vectorB;
		static vector _indexConnections;
		static double _vector_struggler;

		PmergeMe() = delete;
		PmergeMe(const PmergeMe &) = delete;
		PmergeMe& operator=(const PmergeMe &) = delete;
		~PmergeMe() = delete;
    public:
        static void runVector(int argc, char *argv[]);
		static void initVectors(int argc, char *argv[]);
		static void isStrugglerInVector(vector& fullVector);
		static void createVectors(vector& fullVector);
		static int getJacobsthal(int n);
		static void insertionSortVectors(vector& vectorA, vector& vectorB);
		static void mergeInsertionVectors(vector& vectorA, const vector& vectorB, vector& _indexConnections);
		inline static void insertElement(vector& vectorA, int element, int end);
		// static int calculateBinarySearchRange(vector& vectorA, int index);
		inline static void calculateBinarySearchRange(vector& vectorA, int index);
};