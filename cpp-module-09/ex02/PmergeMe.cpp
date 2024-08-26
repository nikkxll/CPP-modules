/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:25:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/26 17:46:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

vector PmergeMe::_vectorA;
vector PmergeMe::_vectorB;
vector PmergeMe::_vectorIndexConnections;
double PmergeMe::_vector_struggler = std::numeric_limits<double>::lowest();

deque PmergeMe::_dequeA;
deque PmergeMe::_dequeB;
deque PmergeMe::_dequeIndexConnections;
double PmergeMe::_deque_struggler = std::numeric_limits<double>::lowest();

void PmergeMe::check(int argc)
{
		std::cout << _vectorA.size() << std::endl;
	if (static_cast<int>(_vectorA.size()) != argc - 1)
	{
		std::cout << "fail" << std::endl;
		throw std::runtime_error("Argument is out of the limits");
	}
	std::cout << _vectorA[0] << std::endl;
	for (size_t i = 1; i < _vectorA.size(); ++i) {
		std::cout << _vectorA[i] << std::endl;
		if (_vectorA[i - 1] > _vectorA[i]) {
			std::cout << "fail" << std::endl;
			throw std::runtime_error("Argument is out of the limits");
		}
	}

	// if (static_cast<int>(_dequeA.size()) != argc - 1)
	// {
	// 	std::cout << "fail" << std::endl;
	// 	throw std::runtime_error("Argument is out of the limits");
	// }
	std::cout << _dequeA[0] << std::endl;
	for (size_t i = 1; i < _dequeA.size(); ++i) {
		std::cout << _dequeA[i] << std::endl;
		if (_dequeA[i - 1] > _dequeA[i]) {
			std::cout << "fail" << std::endl;
			throw std::runtime_error("Argument is out of the limits");
		}
	}
}

void PmergeMe::execute(int argc, char *argv[])
{
	try {
		vector temp;

		readArgv(argc, argv, temp);
		runSort(temp, argv);
		check(argc);
		
	} catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void PmergeMe::readArgv(int argc, char *argv[], vector& temp)
{
	for (int i = 1; i < argc; i++) {
		double curr = std::stod(argv[i]);
		if (curr < 0 || curr > std::numeric_limits<int>::max())
			throw std::runtime_error("Argument is out of the limits");
		temp.push_back(curr);
	}
}

void PmergeMe::print(char *argv[], double firstInterval, double secondInterval)
{
	std::cout << "Before: ";
	for (size_t i = 1; argv[i] != NULL; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < _vectorA.size(); ++i)
		std::cout << _vectorA[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vectorA.size() << " elements with std::vector : ";
	std::cout << firstInterval << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeA.size() << " elements with std::deque : ";
	std::cout << secondInterval << " us" << std::endl;
}

void PmergeMe::runSort(vector& fullVector, char *argv[])
{
	auto vecSortStart = std::chrono::high_resolution_clock::now();
	initVectors(fullVector);
	insertionSortVectors();
	mergeInsertionSortVectors();
	auto vecSortEnd = std::chrono::high_resolution_clock::now();
	double vecDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(vecSortEnd - vecSortStart).count() / 1000.0;
	
	auto deqSortStart = std::chrono::high_resolution_clock::now();
	initDeques(fullVector);
	insertionSortDeques();
	mergeInsertionSortDeques();
	auto deqSortEnd = std::chrono::high_resolution_clock::now();
	double deqDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(deqSortEnd - deqSortStart).count() / 1000.0;
	
	print(argv, vecDuration, deqDuration);
}

int PmergeMe::getJacobsthal(int n)
{
	if (n < 1) throw std::runtime_error("Jacobsthal number getter error");
	if (n == 1) return 1;

	return pow(2, n) - getJacobsthal(n - 1);
}

/*
Merge insertion sort using std::vector
*/
void PmergeMe::initVectors(vector& fullVector)
{
	if (fullVector.size() % 2 != 0) {
		_vector_struggler = fullVector[fullVector.size() - 1];
		fullVector.pop_back();
	}
	
	if (fullVector.empty()) return;
	size_t n = fullVector.size();

	_vectorA.reserve(n + 1);
	_vectorB.reserve(n + 1);
	_vectorIndexConnections.reserve(n + 1);

	for (size_t i = 0; i < n - 1; i += 2) {
		if (fullVector[i] > fullVector[i + 1])
			std::swap(fullVector[i], fullVector[i + 1]);
	}
	for (size_t i = 0; i < fullVector.size(); ++i) {
		if (i % 2 != 0)	_vectorA.push_back(fullVector[i]);
		else			_vectorB.push_back(fullVector[i]);
	}
	for (size_t i = 0; i < _vectorA.size(); ++i)
		_vectorIndexConnections.push_back(i);
}

void PmergeMe::insertionSortVectors()
{
	int n = _vectorA.size();

	for (int i = 1; i < n; ++i) {
		int keyA = _vectorA[i];
		int keyB = _vectorB[i];
		int j = i - 1;
		
		while (j >= 0 && _vectorA[j] > keyA) {
			_vectorA[j + 1] = _vectorA[j];
			_vectorB[j + 1] = _vectorB[j];
			--j;
		}
		_vectorA[j + 1] = keyA;
		_vectorB[j + 1] = keyB;
	}
}

inline void PmergeMe::insertElementVector(int element, int end)
{
	auto insertion_point = std::upper_bound(_vectorA.begin(), _vectorA.begin() + end, element);
	incrementIndexesVector(insertion_point - _vectorA.begin());
	_vectorA.insert(insertion_point, element);
}

inline void PmergeMe::incrementIndexesVector(int index)
{
	auto it = std::lower_bound(_vectorIndexConnections.begin(), _vectorIndexConnections.end(), index);

	if (it != _vectorIndexConnections.end())
		std::transform(it, _vectorIndexConnections.end(), it, [](int v) { return v + 1; });
}

void PmergeMe::mergeInsertionSortVectors()
{
	int size = _vectorB.size();
	int lastJacobIndex = 1;
	bool shiftingFlag = false;

	if (!(_vectorB.empty())) insertElementVector(_vectorB[0], _vectorIndexConnections[0]);
	for (int i = 1; i <= size; ++i) {
		int jacobIndex = getJacobsthal(lastJacobIndex + 1) - 1;
		if (jacobIndex >= size) break;
		
		insertElementVector(_vectorB[jacobIndex],_vectorIndexConnections[jacobIndex]);
		int processRemain = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
		for (int j = jacobIndex - 1; j >= processRemain; --j)
			insertElementVector(_vectorB[j], _vectorIndexConnections[j]);
		lastJacobIndex = jacobIndex;
		shiftingFlag = true;
	}

	int finalize = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
	for (int i = finalize; i < size; ++i)
		insertElementVector(_vectorB[i], _vectorIndexConnections[i]);

	if (_vector_struggler != std::numeric_limits<double>::lowest())
		insertElementVector(_vector_struggler, _vectorA.size());
}

/*
Merge insertion sort using std::deque
*/
void PmergeMe::initDeques(vector& fullVector)
{
	if (fullVector.size() % 2 != 0) {
		_deque_struggler = fullVector[fullVector.size() - 1];
		fullVector.pop_back();
	}
	
	if (fullVector.empty()) return;
	size_t n = fullVector.size();

	for (size_t i = 0; i < n - 1; i += 2) {
		if (fullVector[i] > fullVector[i + 1])
			std::swap(fullVector[i], fullVector[i + 1]);
	}
	for (size_t i = 0; i < fullVector.size(); ++i) {
		if (i % 2 != 0)	_dequeA.push_back(fullVector[i]);
		else			_dequeB.push_back(fullVector[i]);
	}
	for (size_t i = 0; i < _dequeA.size(); ++i)
		_dequeIndexConnections.push_back(i);
}

void PmergeMe::insertionSortDeques()
{
	int n = _dequeA.size();

	for (int i = 1; i < n; ++i) {
		int keyA = _dequeA[i];
		int keyB = _dequeB[i];
		int j = i - 1;
		
		while (j >= 0 && _dequeA[j] > keyA) {
			_dequeA[j + 1] = _dequeA[j];
			_dequeB[j + 1] = _dequeB[j];
			--j;
		}
		_dequeA[j + 1] = keyA;
		_dequeB[j + 1] = keyB;
	}
}

inline void PmergeMe::insertElementDeque(int element, int end)
{
	auto insertion_point = std::upper_bound(_dequeA.begin(), _dequeA.begin() + end, element);
	incrementIndexesVector(insertion_point - _dequeA.begin());
	_dequeA.insert(insertion_point, element);
}

inline void PmergeMe::incrementIndexesDeque(int index)
{
	auto it = std::lower_bound(_dequeIndexConnections.begin(), _dequeIndexConnections.end(), index);

	if (it != _dequeIndexConnections.end())
		std::transform(it, _dequeIndexConnections.end(), it, [](int v) { return v + 1; });
}

void PmergeMe::mergeInsertionSortDeques()
{
	int size = _dequeB.size();
	int lastJacobIndex = 1;
	bool shiftingFlag = false;

	if (!(_dequeB.empty())) insertElementVector(_dequeB[0], _dequeIndexConnections[0]);
	for (int i = 1; i <= size; ++i) {
		int jacobIndex = getJacobsthal(lastJacobIndex + 1) - 1;
		if (jacobIndex >= size) break;
		
		insertElementVector(_dequeB[jacobIndex],_dequeIndexConnections[jacobIndex]);
		int processRemain = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
		for (int j = jacobIndex - 1; j >= processRemain; --j)
			insertElementVector(_dequeB[j], _dequeIndexConnections[j]);
		lastJacobIndex = jacobIndex;
		shiftingFlag = true;
	}

	int finalize = shiftingFlag ? lastJacobIndex + 1 : lastJacobIndex;
	for (int i = finalize; i < size; ++i)
		insertElementVector(_dequeB[i], _dequeIndexConnections[i]);

	if (_deque_struggler != std::numeric_limits<double>::lowest())
		insertElementVector(_deque_struggler, _dequeA.size());
}
