/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:37:42 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/10 18:37:43 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>
#include <algorithm>
#include <bits/types/struct_timeval.h>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <utility>
#include <vector>

PmergeMe::PmergeMe( void ) {
	return ;
}

PmergeMe::~PmergeMe( void ) {
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& to_copy) {
	(void)to_copy;
	return ;
}

PmergeMe&		PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;
	return (*this);
}

const char*	PmergeMe::wrongInput::what() const throw() {
	return ("Error : Invalid input parameters");
}

const char*	PmergeMe::doubleOccurence::what() const throw() {
	return ("Error : Double occurence of a number");
}

void	printVec(std::vector<int>& v) {
	for (int_it it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::vectorSort(char **numbers, int ac) {
	long	number;
	char	*endptr;
	struct timeval tb, te;

	gettimeofday(&tb, NULL);
	for(int i = 0; i < ac; ++i) {
		number = std::strtol(numbers[i], &endptr, 10);
		if (errno == ERANGE || number < 0 || number > INT_MAX || *endptr != '\0') {
			throw wrongInput();
		} 
		else if (std::find(this->_intVect.begin(), this->_intVect.end(), number)
				!= this->_intVect.end()) {
			throw doubleOccurence();
		}
		this->_intVect.push_back(number);
	}
	this->_vecMergeSort(this->_intVect, 1);
	printVec(this->_intVect);
	gettimeofday(&te, NULL);
}

void	printPairs(std::vector<pairs>& v) {
	for (pairs_it it = v.begin(); it != v.end(); ++it) {
		std::cout << it->first << "|" << it->second << " ";
	}
	std::cout << std::endl;
}

inline bool PmergeMe::_checkReminder(std::vector<int>& current, size_t itSize) const {
	if (current.size() % (itSize * 2) >= itSize) {
		return (true);
	} return (false);
}

void PmergeMe::_permutePairs(std::vector<int>& current, size_t itSize) {
	for (int_it it = current.begin(); it + itSize < current.end(); it += itSize * 2) {
		if (*it < *(it + itSize)) {
			int tmp = *it;
			*it = *(it + itSize);
			*(it + itSize) = tmp;
		}
	}
	return ;
}

void	PmergeMe::_insert(std::vector<int>& current, const int_it& begin,
		const int_it& end, const int_it& where) {
	std::vector<int> tmp(begin, end);
	printVec(tmp);
	current.erase(begin, end);
	current.insert(where, tmp.begin(), tmp.end());
}

void	PmergeMe::_extract(std::vector<int>& src, std::vector<int>& dest,
			const int_it& where, const int_it& dest_insert, int itSize) {
	dest.insert(dest_insert, where, where + itSize);
	src.erase(where, (where + itSize));
}

int_it	PmergeMe::_getNextJacobsthal(int &actual, int &prev, int itSize, std::vector<int>& current) {
	const int old_prev = prev;
	prev = actual;
	actual = prev + (2 * old_prev);
	if (current.size() >= static_cast<size_t>(actual - prev) * itSize) {
		return (current.begin() + ((actual - prev) * itSize) - itSize);
	} else return (current.end() - itSize);
}

int_it			PmergeMe::_binarySearch(const int_it& full_range_begin,
		const int_it& full_range_end, int to_insert, int itSize) {
	int_it range_end = full_range_end; int_it range_begin = full_range_begin;
	while (1) {
		int_it middle = range_begin + ((range_end - range_begin) / 2);
		if (middle == range_begin) {
			if (to_insert < *middle) {
				return (range_begin);
			} else {
				return (range_begin + itSize);
			}
		} else if (middle == range_end) {
			if (to_insert < *middle) {
				return (range_end - 1);
			} else {
				return (range_end + itSize);
			}
		} else if (to_insert > *middle && to_insert < *(middle + itSize)) {
			return (middle + itSize);
		} else if (to_insert < *middle && to_insert > *(middle - itSize)) {
			return (middle - 1);
		} else if (to_insert < *middle) {
			range_begin = middle + 1;
		} else {
			range_end = middle - 1;
		}
	}
	return (range_end);
	}

std::vector<int>	PmergeMe::_vecInsert( std::vector<int> current, size_t itSize) {
	std::cout << "Recursion place : " << itSize << std::endl;
	std::vector<int> main, pending;
	int jacob_num = 1, old_jacob = 0;
	while (current.size() >= itSize * 2) {
		std::cout << "iter" << std::endl;
		_extract(current, main, current.begin(), main.end(), itSize);
		_extract(current, pending, current.begin(), pending.end(), itSize);
	}
	std::cout << "Main Chain : ";
	printVec(main);
	std::cout << "Pending : ";
	printVec(pending);
	std::cout << "Current : ";
	printVec(current);
	_extract(pending, main, pending.begin(), main.begin(), itSize);	
	std::cout << "Main Chain : ";
	printVec(main);
	std::cout << "Pending : ";
	printVec(pending);
	std::cout << "Current : ";
	printVec(current);
	std::cout << "Pending size : " << pending.size() << std::endl;
	while ( pending.size() != 0) {
		int_it it = _getNextJacobsthal(jacob_num, old_jacob, itSize, pending);
		int_it	insert_range_end = main.begin() + ((old_jacob * 2) + 1);
		int_it where_to_insert;
		where_to_insert = _binarySearch(main.begin(), insert_range_end, *it, itSize);
		// it -= itSize;
		insert_range_end = where_to_insert - itSize;
		for (; it >= pending.begin(); it -= itSize) {
			std::cout << "One iter" << *it << itSize <<  std::endl;
			where_to_insert = _binarySearch(main.begin(), insert_range_end, *it, itSize);
			std::cout << "Seggy" << *where_to_insert << " " << *it <<std::endl;
			printVec(pending);
			main.insert(where_to_insert, it, it + itSize);
			insert_range_end = where_to_insert - itSize;
			std::cout << "Vector : ";
			printVec(main);
		} 
	}
	std::cout << "I get there lol" << std::endl;
	if (current.size() != 0) {
		_extract(current, main, current.begin(), _binarySearch(main.begin(), main.end() - itSize, *(current.begin()), itSize), itSize);
	}
	std::cout << "Main Chain : ";
	printVec(main);
	std::cout << "Pending : ";
	printVec(pending);
	std::cout << "Current : ";
	printVec(current);
	return main;
}

std::vector<int> PmergeMe::_vecMergeSort( std::vector<int> current, size_t itSize) {
	std::cout << itSize << std::endl;
	if (itSize * 2 > current.size()) {
		return current;
	}
	this->_permutePairs(current, itSize);
	printVec(current);
	std::vector<int> sorted = _vecMergeSort(current, itSize * 2);
	sorted = _vecInsert(current, itSize);
	std::cout << "Sorted : ";
	printVec(sorted);
	return sorted;

}
