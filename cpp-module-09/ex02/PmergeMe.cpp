/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/24 18:19:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int PmergeMe::_jacob = 2;
std::vector<int> PmergeMe::_vectorA;
std::vector<int> PmergeMe::_vectorB;
double PmergeMe::_vector_struggler = std::numeric_limits<double>::lowest();

void PmergeMe::runVector(int argc, char *argv[])
{
    try {
        initVectors(argc, argv);
        for (auto it: _vectorA)
            std::cout << "in a" << it << std::endl;
        for (auto it: _vectorB)
            std::cout << "in b" << it << std::endl;
        insertionSortVectors(_vectorA, _vectorB);
        for (auto it: _vectorA)
            std::cout << "after in a" << it << std::endl;
        for (auto it: _vectorB)
            std::cout << "after in b" << it << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void PmergeMe::initVectors(int argc, char *argv[])
{
    std::vector<int> temp;
    
    for (int i = 1; i < argc; i++) {
        double curr = std::stod(argv[i]);
        if (curr < std::numeric_limits<int>::min() || curr > std::numeric_limits<int>::max())
            throw std::runtime_error("Arg is out of the integer limits");
        temp.push_back(curr);
    }
    isStrugglerInVector(temp);
    createVectors(temp);
}

void PmergeMe::isStrugglerInVector(std::vector<int>& fullVector)
{
    if (fullVector.size() % 2 != 0) {
        _vector_struggler = fullVector[fullVector.size() - 1];
        fullVector.pop_back();
    }
}

void PmergeMe::createVectors(std::vector<int>& fullVector)
{
    size_t n = fullVector.size();
    for (size_t i = 0; i < n - 1; i += 2) {
        if (fullVector[i] > fullVector[i + 1]) {
            std::swap(fullVector[i], fullVector[i + 1]);
        }
    }
    for (size_t i = 0; i < fullVector.size(); ++i) {
        if (i % 2 != 0) _vectorA.push_back(fullVector[i]);
        else            _vectorB.push_back(fullVector[i]);
    }
}

int PmergeMe::getJacobsthal(int n)
{
    if (n < 1) throw std::runtime_error("Jacobsthal number getter error");
    if (n == 1) return 1;
    
    return pow(2, n) - getJacobsthal(n - 1);
}

void PmergeMe::insertionSortVectors(std::vector<int>& vectorA, std::vector<int>& vectorB)
{
    int n = vectorA.size();
    
    for (int i = 1; i < n; ++i) {
        int keyA = vectorA[i];
        int keyB = vectorB[i];
        int j = i - 1;
        
        while (j >= 0 && vectorA[j] > keyA) {
            vectorA[j + 1] = vectorA[j];
            vectorB[j + 1] = vectorB[j];
            --j;
        }
        vectorA[j + 1] = keyA;
        vectorB[j + 1] = keyB;
    }
}