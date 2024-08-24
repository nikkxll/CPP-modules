/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/24 23:50:51 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

std::vector<int> PmergeMe::_vectorA;
std::vector<int> PmergeMe::_vectorB;
double PmergeMe::_vector_struggler = std::numeric_limits<double>::lowest();

void PmergeMe::runVector(int argc, char *argv[])
{
    try {
        initVectors(argc, argv);
        insertionSortVectors(_vectorA, _vectorB);
        mergeInsertionVectors(_vectorA, _vectorB);
        for (auto it: _vectorA)
            std::cout << "after all" << it << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void PmergeMe::initVectors(int argc, char *argv[])
{
    std::vector<int> temp;
    
    for (int i = 1; i < argc; i++) {
        double curr = std::stod(argv[i]);
        if (curr < 0 || curr > std::numeric_limits<int>::max())
            throw std::runtime_error("Argument is out of the limits");
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
    if (fullVector.empty()) return;
    size_t n = fullVector.size();
    
    _vectorA.reserve(n + 1);
    _vectorB.reserve(n / 2);
    
    for (size_t i = 0; i < n - 1; i += 2) {
        if (fullVector[i] > fullVector[i + 1])
            std::swap(fullVector[i], fullVector[i + 1]);
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

void PmergeMe::insertElement(std::vector<int>& vectorA, int element)
{
    auto insertion_point = std::upper_bound(vectorA.begin(), vectorA.end(), element);
    vectorA.insert(insertion_point, element);
}

void PmergeMe::mergeInsertionVectors(std::vector<int>& vectorA, const std::vector<int>& vectorB)
{
    int size = vectorB.size();
    int lastJacobIndex = 1;
    bool shiftingFlag = false;

    if (!(vectorB.empty())) vectorA.insert(vectorA.begin(), vectorB[0]);
    for (int i = 1; i <= size; ++i) {
        int jacobIndex = getJacobsthal(lastJacobIndex + 1) - 1;
        if (jacobIndex >= size) break;
        
        insertElement(vectorA, vectorB[jacobIndex]);
        for (int j = jacobIndex - 1; j >= lastJacobIndex; --j)
            insertElement(vectorA, vectorB[j]);
        lastJacobIndex = jacobIndex;
        shiftingFlag = true;
    }

    int startIndex = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
    for (int i = startIndex; i < size; ++i)
        insertElement(vectorA, vectorB[i]);
    
    if (_vector_struggler != std::numeric_limits<double>::lowest())
        insertElement(vectorA, _vector_struggler);
}
