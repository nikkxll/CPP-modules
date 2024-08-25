/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/25 23:24:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

vector PmergeMe::_vectorA;
vector PmergeMe::_vectorB;
vector PmergeMe::_indexConnections;
double PmergeMe::_vector_struggler = std::numeric_limits<double>::lowest();

void PmergeMe::runVector(int argc, char *argv[])
{
    try {
        if (static_cast<int>(_vectorA.size()) != argc - 1)
        {
            std::cout << "fail" << std::endl;
            throw std::runtime_error("Argument is out of the limits");
        }
        for (size_t i = 1; i < _vectorA.size(); ++i) {
            std::cout << _vectorA[i] << std::endl;
            if (_vectorA[i - 1] > _vectorA[i]) {
                std::cout << "fail" << std::endl;
                throw std::runtime_error("Argument is out of the limits");
            }
        }
        std::cout << "OK: argc:" << argc - 1 << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void PmergeMe::initVectors(int argc, char *argv[])
{
    vector temp;
    
    for (int i = 1; i < argc; i++) {
        double curr = std::stod(argv[i]);
        if (curr < 0 || curr > std::numeric_limits<int>::max())
            throw std::runtime_error("Argument is out of the limits");
        temp.push_back(curr);
    }
    isStrugglerInVector(temp);
    createVectors(temp);
}

void PmergeMe::isStrugglerInVector(vector& fullVector)
{
    if (fullVector.size() % 2 != 0) {
        _vector_struggler = fullVector[fullVector.size() - 1];
        fullVector.pop_back();
    }
}

void PmergeMe::createVectors(vector& fullVector)
{
    if (fullVector.empty()) return;
    size_t n = fullVector.size();
    
    _vectorA.reserve(n + 1);
    _vectorB.reserve(n / 2);
    _indexConnections.reserve(n + 1);
    
    for (size_t i = 0; i < n - 1; i += 2) {
        if (fullVector[i] > fullVector[i + 1])
            std::swap(fullVector[i], fullVector[i + 1]);
    }
    for (size_t i = 0; i < fullVector.size(); ++i) {
        if (i % 2 != 0) _vectorA.push_back(fullVector[i]);
        else            _vectorB.push_back(fullVector[i]);
    }
    for (size_t i = 0; i < _vectorA.size(); ++i)
        _indexConnections.push_back(i);
}

int PmergeMe::getJacobsthal(int n)
{
    if (n < 1) throw std::runtime_error("Jacobsthal number getter error");
    if (n == 1) return 1;
    
    return pow(2, n) - getJacobsthal(n - 1);
}

void PmergeMe::insertionSortVectors(vector& vectorA, vector& vectorB)
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

void PmergeMe::insertElement(vector& vectorA, int element, int end)
{
    auto insertion_point = std::upper_bound(vectorA.begin(), vectorA.begin() + end, element);
    auto index = std::distance(vectorA.begin(), insertion_point);
    vectorA.insert(insertion_point, element);
    _indexConnections.insert(_indexConnections.begin() + index, -1);
}

void PmergeMe::mergeInsertionVectors(vector& vectorA, const vector& vectorB, vector& _indexConnections)
{
    int size = vectorB.size();
    int lastJacobIndex = 1;
    bool shiftingFlag = false;

    if (!(vectorB.empty())) insertElement(vectorA, vectorB[0], 0);
    for (int i = 1; i <= size; ++i) {
        int jacobIndex = getJacobsthal(lastJacobIndex + 1) - 1;
        if (jacobIndex >= size) break;
        
        insertElement(vectorA, vectorB[jacobIndex], calculateBinarySearchRange(_indexConnections, jacobIndex));
        
        int processRemain = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
        for (int j = jacobIndex - 1; j >= processRemain; --j)
            insertElement(vectorA, vectorB[j], calculateBinarySearchRange(_indexConnections, j));
        lastJacobIndex = jacobIndex;
        shiftingFlag = true;
    }

    int finalize = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
    for (int i = finalize; i < size; ++i)
        insertElement(vectorA, vectorB[i], calculateBinarySearchRange(_indexConnections, i));
    
    if (_vector_struggler != std::numeric_limits<double>::lowest())
        insertElement(vectorA, _vector_struggler, vectorA.size());
}

int PmergeMe::calculateBinarySearchRange(vector& vec, int index)
{
    auto it = std::find(vec.begin(), vec.end(), index);

    if (it != vec.end()) return std::distance(vec.begin(), it);
    else throw std::runtime_error("Binary search error");
}
