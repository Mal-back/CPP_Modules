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
	if (current.size() >= (actual - prev) * itSize) {
		return (current.begin() + ((actual - prev) * itSize) - itSize);
	} else return (current.end() - itSize);
}

void	PmergeMe::_vecInsert( std::vector<int>& current, size_t itSize) {
	std::vector<int> main, pending;
	int jacob_num = 1, old_jacob = 0;
	while (current.size() >= itSize * 2) {
		std::cout << "iter" << std::endl;
		_extract(current, main, current.begin(), main.end(), itSize);
		_extract(current, pending, current.begin(), pending.end(), itSize);
	}
	_extract(pending, main, pending.begin(), main.begin(), itSize);	
	while ( pending.size() != 0) {
		for (int_it it = _getNextJacobsthal(jacob_num, old_jacob, itSize, pending);
				it >= pending.begin(); it -= itSize) {
		} 
	}
	if (current.size() != 0) {

	}
	std::cout << "Main Chain : ";
	printVec(main);
	std::cout << "Pending : ";
	printVec(pending);
	std::cout << "Current : ";
	printVec(current);
}

void PmergeMe::_vecMergeSort( std::vector<int>& current, size_t itSize) {
	std::cout << itSize << std::endl;
	if (itSize * 2 > current.size()) {
		return;
	}
	this->_permutePairs(current, itSize);
	printVec(current);
	_vecMergeSort(current, itSize * 2);
	_vecInsert(current, itSize);
	return;

}
