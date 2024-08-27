/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:15 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/27 12:59:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <iomanip>

using vector = std::vector<int>;
using deque = std::deque<int>;

class PmergeMe {
	private:
		static void readArgv(int argc, char *argv[], vector& temp);
		static void print(char *argv[], double firstInterval, double secondInterval);
		static void runSort(vector& initArgsStorageForVector, vector& initArgsStorageForDeque, char *argv[]);
		static int getJacobsthal(int n);
		
		PmergeMe() = delete;
		PmergeMe(const PmergeMe &) = delete;
		PmergeMe& operator=(const PmergeMe &) = delete;
		~PmergeMe() = delete;
		
		/*
			std::vector
		*/
		static vector _vectorA;
		static vector _vectorB;
		static vector _vectorIndexConnections;
		static double _vector_struggler;
		
		static void initVectors(vector& fullVector);
		static void insertionSortVectors();
		static void mergeInsertionSortVectors();
		inline static void insertElementVector(int element, int end);
		inline static void incrementIndexesVector(int index);

		/*
			std::deque
		*/
		static deque _dequeA;
		static deque _dequeB;
		static deque _dequeIndexConnections;
		static double _deque_struggler;

		static void initDeques(vector& fullVector);
		static void insertionSortDeques();
		static void mergeInsertionSortDeques();
		inline static void insertElementDeque(int element, int end);
		inline static void incrementIndexesDeque(int index);

	public:
		static void execute(int argc, char *argv[]);
};