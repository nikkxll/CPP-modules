/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/26 16:55:50 by dnikifor         ###   ########.fr       */
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
		static void execute(int argc, char *argv[]);
		static void readArgv(int argc, char *argv[], vector& temp);
		static void print(vector& fullVector, double firstInterval, double secondInterval);
		
		static void runSort(vector& fullVector);
		static void initVectors(vector& fullVector);
		static int getJacobsthal(int n);
		static void insertionSortVectors();
		static void mergeInsertionSortVectors();
		inline static void insertElementVector(int element, int end);
		inline static void incrementIndexesVector(vector& vectorA, int index);

		// static void check(int argc);
};