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
#include <cstddef>
#include <iostream>
#include <iterator>
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
		std::cout << "Comapring " << *it << " and " << *(it + itSize) << std::endl;
		if (*it < *(it + itSize)) {
			for (int_it perm = it; perm != it + itSize; ++perm) {
				int tmp = *perm;
				*perm = *(perm + itSize);
				*(perm + itSize) = tmp;
			}
		}
	}
	printVec(current);
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

int_it	PmergeMe::_getNextJacobsthal(int &actual, int &prev, int itSize, std::vector<int>& current, int_it starting_point) {
	const int old_prev = prev;
	prev = actual;
	actual = prev + (2 * old_prev);
	std::cout << "Pending size :" << current.size() << std::endl;
	std::cout << "Condition :" << static_cast<size_t>(actual - prev) * itSize << std::endl;
	if (actual - prev == 0) {
		if (current.size() - (starting_point - current.begin()) >= static_cast<size_t>(2 * itSize)) {
			return starting_point + (2 * itSize);
		} else {
			return (current.end() - itSize);
		}
	}
	if (current.size() - ( starting_point - current.begin()) >= static_cast<size_t>(actual - prev) * itSize) {
		std::cout << "return this" << std::endl;
		return (starting_point + ((actual - prev) * itSize) - itSize);
	} else return (current.end() - itSize);
}

int_it			PmergeMe::_binarySearch(const int_it& full_range_begin,
		const int_it& full_range_end, int to_insert, int itSize) {
	// if (itSize == 1) {
	// 	std::cout << "Je vais faire seggy" << std::endl;
	// 	int_it ret = std::lower_bound(full_range_begin, full_range_begin, to_insert) - 1;
	// 	std::cout << "LB return : " << *ret << std::endl;
	// 	return (ret);
	// }
	int_it range_end = full_range_end; int_it range_begin = full_range_begin;
	while (range_begin <= range_end) {
		std::cout << "cc" << std::endl;
		int_it middle;
		int size = 0;
		for (; range_begin != range_end; range_begin += itSize, ++size) {}
		range_begin -= size * itSize;
		middle = range_begin + ((size / 2) * itSize);
		std::cout << "Middle : " << *middle << std::endl;
		if (middle == full_range_begin) {
			if (to_insert < *middle) {
				return (range_begin);
			} else {
				return (range_begin + itSize);
			}
		} else if (middle == full_range_end) {
			if (to_insert < *middle) {
				return (range_end);
			} else {
				return (range_end + itSize);
			}
		} else if (to_insert > *middle && to_insert < *(middle + itSize)) {
			return (middle + itSize);
		} else if (to_insert < *middle && to_insert > *(middle - itSize)) {
			return (middle);
		} else if (to_insert > *middle) {
			if (itSize == 1) {
				range_begin = middle + 1;
			} else 
			range_begin = middle;
		} else {
			range_end = middle;
		}
	}
	return (range_end);
	}

std::vector<int>	PmergeMe::_vecInsert( std::vector<int>& current, size_t itSize) {
	std::cout << "Recursion place : " << itSize << std::endl;
	printVec(current);
	std::vector<int> main, pending;
	int jacob_num = 1, old_jacob = 1;
	int_it inserter;
	for (inserter = current.begin(); inserter + (itSize * 2) <= current.end(); inserter += itSize) {
		main.insert(main.end(), inserter, inserter + itSize);
		inserter += itSize;
		pending.insert(pending.end(), inserter, inserter + itSize);
		if (itSize == 2) {
			std::cout << "After a current splitting round, main : "; 
			printVec(main);
			std::cout << "And pending : ";
			printVec(pending);
		}
	}
	int_it	already_inserted = pending.begin();
	main.insert(main.begin(), pending.begin(), pending.begin() + itSize);
	already_inserted += itSize;
	std::cout << "After inserting b1" << std::endl;
	std::cout << "Main Chain : ";
	printVec(main);
	std::cout << "Pending : ";
	printVec(pending);
	while (already_inserted <= pending.end() - itSize) {
		int_it	to_insert = _getNextJacobsthal(jacob_num, old_jacob, itSize, pending, already_inserted);
		std::cout << "Find want to insert : " << *to_insert << std::endl;
		printVec(pending);
		int_it	range_end = main.begin() + (((old_jacob * 2) * itSize) + itSize);
		int_it	where_to = _binarySearch(main.begin(), range_end, *to_insert, itSize);
		std::cout << *to_insert << " " << *where_to << std::endl;
		size_t offset = range_end - main.begin();
		main.insert(where_to, to_insert, to_insert + itSize);
		range_end = main.begin() + offset + itSize;
		std::cout << *where_to << std::endl;
		std::cout << "Before incr" << *to_insert << std::endl;
		to_insert -= itSize;
		std::cout << "After incr " << *to_insert << std::endl;
		// std::cout << "to insert : " << *to_insert << "  pending begin :" << *pending.begin() << std::endl;
		std::cout << "Main Chain : ";
		printVec(main);
		while (to_insert >= already_inserted) {
			std::cout << "In the subloop" << std::endl;
			where_to = _binarySearch(main.begin(), where_to + (2 * itSize), *to_insert, itSize);
			std::cout << *to_insert << " will be inserted here : " << *where_to << std::endl;
			offset = range_end - main.begin();
			main.insert(where_to, to_insert, to_insert + itSize);
			range_end = main.begin() + offset + itSize;
			std::cout << *to_insert << std::endl;
			to_insert -= itSize;
			std::cout << *to_insert << std::endl;
			std::cout << "Main Chain : ";
			printVec(main);
			std::cout << "Pending : ";
			printVec(pending);
		}
		already_inserted += (jacob_num - old_jacob) * itSize; 
	}
	std::cout << "I get there lol" << std::endl;
	if (current.end() - inserter >= static_cast<long>(itSize)) {
		int_it where_to = _binarySearch(main.begin(), main.end() - itSize, *inserter, itSize);
		main.insert(where_to, inserter, inserter + itSize);
		inserter += itSize;
		if (inserter != current.end()) {
			main.insert(main.end(), inserter, current.end());
		}
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
	std::vector<int> ret = _vecMergeSort(current, itSize * 2);
	std::cout << "Sorted after return: ";
	printVec(ret);
	std::vector<int> sorted = _vecInsert(ret, itSize);
	std::cout << "Sorted before return: ";
	printVec(sorted);
	return sorted;

}
