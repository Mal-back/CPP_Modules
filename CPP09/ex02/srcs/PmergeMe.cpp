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
#include <ctime>
#include <iomanip>
#include <ios>
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

// void	printVec(std::vector<int>& v, size_t itSize) {
// 	for (int_it it = v.begin(); it != v.end(); ++it) {
// 		if ((it - v.begin()) % itSize == 0) {
// 			std::cout << " |";
// 		}
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

void	PmergeMe::vectorSort(char **numbers, int ac) {
	long	number;
	char	*endptr;
	clock_t	ts, te;

	ts = clock();
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
	std::vector<int> ret = this->_vecMergeSort(this->_intVect, 1);
	if (std::is_sorted(ret.begin(), ret.end()) == true) {
		std::cout << "All good boss" << std::endl;
	} else {
		std::cout << "Oh oh" << std::endl;
	}
	te = clock() - ts;
	std::cout << "took " << std::fixed << std::setprecision(5) << (static_cast<double>(te) / static_cast<float>(CLOCKS_PER_SEC)) << std::endl;
}

void PmergeMe::_permutePairs(std::vector<int>& current, size_t itSize) {
	for (int_it it = current.begin(); it + (2 * itSize) <= current.end(); it += itSize * 2) {
		if (*it < *(it + itSize)) {
			for (int_it perm = it; perm != it + itSize; ++perm) {
				int tmp = *perm;
				*perm = *(perm + itSize);
				*(perm + itSize) = tmp;
			}
		}
	}
	return ;
}

int_it	PmergeMe::_getNextJacobsthal(int &actual, int &prev, int itSize, std::vector<int>& current, int_it starting_point) {
	const int old_prev = prev;
	prev = actual;
	actual = prev + (2 * old_prev);
	if (actual - prev == 0) {
		if (current.size() - (starting_point - current.begin()) >= static_cast<size_t>(2 * itSize)) {
			return starting_point + (2 * itSize);
		} else {
			return (current.end() - itSize);
		}
	}
	if (current.size() - ( starting_point - current.begin()) >= static_cast<size_t>(actual - prev) * itSize) {
		return (starting_point + ((actual - prev) * itSize) - itSize);
	} else return (current.end() - itSize);
}

int_it			PmergeMe::_binarySearch(const int_it& full_range_begin,
		const int_it& full_range_end, int to_insert, int itSize) {
	int_it range_end = full_range_end; int_it range_begin = full_range_begin;
	while (range_begin <= range_end) {
		int_it middle;
		int size = 0;
		for (; range_begin <= range_end; range_begin += itSize, ++size) {}
		range_begin -= size * itSize;
		middle = range_begin + ((size / 2) * itSize);
		if (middle > full_range_end) {
			middle = full_range_end;
		} else if (middle < full_range_begin) {
			middle = full_range_begin;
		}
		if (middle == full_range_begin) {
			if (to_insert < *middle) {
				return (range_begin);
			} else if (to_insert < *(middle + itSize)){
				return (range_begin + itSize);
			}
		} if (middle == full_range_end) {
			if (to_insert > *middle) {
				return (range_end + itSize);
			} else if (to_insert < *middle && to_insert > *(middle - itSize)){
				return (range_end);
			}
		} if (to_insert > *middle && to_insert < *(middle + itSize)) {
			return (middle + itSize);
		} if (to_insert < *middle && to_insert > *(middle - itSize)) {
			return (middle);
		} if (to_insert > *middle) {
			range_begin = middle + itSize;
		} else {
			range_end = middle - itSize;
		}
	}
	return (range_begin);
	}

std::vector<int>	PmergeMe::_vecInsert( std::vector<int>& current, size_t itSize) {
	std::vector<int> main, pending;
	int jacob_num = 1, old_jacob = 1;
	int_it inserter;
	for (inserter = current.begin(); inserter + (itSize * 2) <= current.end(); inserter += itSize) {
		main.insert(main.end(), inserter, inserter + itSize);
		inserter += itSize;
		pending.insert(pending.end(), inserter, inserter + itSize);
	}
	int_it	already_inserted = pending.begin();
	main.insert(main.begin(), pending.begin(), pending.begin() + itSize);
	already_inserted += itSize;
	while (already_inserted <= pending.end() - itSize) {
		int_it	to_insert = _getNextJacobsthal(jacob_num, old_jacob, itSize, pending, already_inserted);
		int_it	range_end = main.begin() + ((jacob_num + old_jacob) * itSize);
		if (range_end > main.end() - itSize) {
			range_end = main.end() - itSize;
		}
		int_it	where_to = _binarySearch(main.begin(), range_end + itSize, *to_insert, itSize);
		size_t offset = range_end - main.begin();
		main.insert(where_to, to_insert, to_insert + itSize);
		range_end = main.begin() + offset + itSize;
		to_insert -= itSize;
		while (to_insert >= already_inserted) {
			where_to = _binarySearch(main.begin(), range_end + itSize, *to_insert, itSize);
			offset = range_end - main.begin();
			main.insert(where_to, to_insert, to_insert + itSize);
			range_end = main.begin() + offset + itSize;
			if (range_end > main.end() - itSize) {
				range_end = main.end() - itSize;
			}
			to_insert -= itSize;
		}
		already_inserted += (jacob_num - old_jacob) * itSize; 
	}
	if (inserter < current.end()) {
		if ( current.end() - inserter >= static_cast<long>(itSize)) {
			int_it where_to = _binarySearch(main.begin(), main.end() - itSize, *inserter, itSize);
			main.insert(where_to, inserter, inserter + itSize);
			inserter += itSize;
		}
		if (inserter != current.end()) {
			main.insert(main.end(), inserter, current.end());
		}
	}
	return main;
}

std::vector<int> PmergeMe::_vecMergeSort( std::vector<int> current, size_t itSize) {
	if (itSize * 2 > current.size()) {
		return current;
	}
	this->_permutePairs(current, itSize);
	// printVec(current, itSize);
	std::vector<int> ret = _vecMergeSort(current, itSize * 2);
	std::vector<int> sorted = _vecInsert(ret, itSize);
	return sorted;

}
