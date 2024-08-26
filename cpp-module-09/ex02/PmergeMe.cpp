/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/26 10:58:48 by dnikifor         ###   ########.fr       */
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
        vector test_vec;
        for (int i = 1; i < argc; ++i)
            test_vec.push_back(std::stod(argv[i]));
            
        initVectors(argc, argv);
        auto vecSortStart = std::chrono::high_resolution_clock::now();
        insertionSortVectors(_vectorA, _vectorB);
        mergeInsertionVectors(_vectorA, _vectorB, _indexConnections);
        auto vecSortEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = vecSortEnd - vecSortStart;
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Sorting took " << duration.count() << " seconds.\n";

        auto newvecSortStart = std::chrono::high_resolution_clock::now();
        std::sort(test_vec.begin(), test_vec.end());
        auto newvecSortEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> newduration = newvecSortEnd - newvecSortStart;
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Sorting took " << newduration.count() << " seconds.\n";
        
        // if (static_cast<int>(_vectorA.size()) != argc - 1)
        // {
        //     std::cout << "fail" << std::endl;
        //     throw std::runtime_error("Argument is out of the limits");
        // }
        // // std::cout << _vectorA[0] << std::endl;
        // for (size_t i = 1; i < _vectorA.size(); ++i) {
        //     // std::cout << _vectorA[i] << std::endl;
        //     if (_vectorA[i - 1] > _vectorA[i]) {
        //         std::cout << "fail" << std::endl;
        //         throw std::runtime_error("Argument is out of the limits");
        //     }
        // }
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
    _indexConnections.reserve(n / 2);
    
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

inline void PmergeMe::insertElement(vector& vectorA, int element, int end)
{
    auto insertion_point = std::upper_bound(vectorA.begin(), vectorA.begin() + end, element);
    int insertion_index = std::distance(vectorA.begin(), insertion_point);
    calculateBinarySearchRange(_indexConnections, insertion_index);
    vectorA.insert(insertion_point, element);
}

inline void PmergeMe::calculateBinarySearchRange(vector& vec, int index)
{
    auto it = std::find(vec.begin(), vec.end(), index);

    if (it != vec.end())
        std::transform(it, vec.end(), it, [](int v) { return v + 1; });
}

void PmergeMe::mergeInsertionVectors(vector& vectorA, const vector& vectorB, vector& _indexConnections)
{
    int size = vectorB.size();
    int lastJacobIndex = 1;
    bool shiftingFlag = false;

    if (!(vectorB.empty())) insertElement(vectorA, vectorB[0], _indexConnections[0]);
    for (int i = 1; i <= size; ++i) {
        int jacobIndex = getJacobsthal(lastJacobIndex + 1) - 1;
        if (jacobIndex >= size) break;
        
        insertElement(vectorA, vectorB[jacobIndex],_indexConnections[jacobIndex]);
        
        int processRemain = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
        for (int j = jacobIndex - 1; j >= processRemain; --j)
            insertElement(vectorA, vectorB[j], _indexConnections[j]);
        lastJacobIndex = jacobIndex;
        shiftingFlag = true;
    }

    int finalize = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
    for (int i = finalize; i < size; ++i)
        insertElement(vectorA, vectorB[i], _indexConnections[i]);
    
    if (_vector_struggler != std::numeric_limits<double>::lowest())
        insertElement(vectorA, _vector_struggler, vectorA.size());
}
