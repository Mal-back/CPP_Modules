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
	std::vector<int> res = this->_vecMergeSort(this->_intVect);
	printVec(res);
	gettimeofday(&te, NULL);
}

void	swapIf(pairs& toCompare) {
	if (toCompare.first < toCompare.second) {
		std::swap(toCompare.first, toCompare.second);
	}
}

int	getFirst(pairs& current) {
	return (current.first);
}

int	getSecond(pairs& current) {
	return (current.second);
}

void	printPairs(std::vector<pairs>& v) {
	for (pairs_it it = v.begin(); it != v.end(); ++it) {
		std::cout << it->first << "|" << it->second << " ";
	}
	std::cout << std::endl;
}

int	get_pending_number( std::vector<pairs> to_search, int n) {
	for (pairs_it it = to_search.begin(); it != to_search.end(); ++it) {
		if (it->first == n) {
			return(it->second);
		}
	}
	return (-1);
}

std::vector<int> PmergeMe::_vecMergeSort( std::vector<int>& current) {
	std::vector<pairs>	paired_vec;
	pairs								tmp;
	int									last_one = -1;
	std::vector<int>		pend;
	std::cout << "Entry :";
	printVec(current);
	if (current.size() < 2) {
		return current;
	}
	for (int_it it = current.begin(); current.size() % 2 == 0 ?
			it != current.end() : it != current.end() - 1; ++it) {
		tmp.first = *it;
		tmp.second = *(++it);
		paired_vec.push_back(tmp);	
	}
	std::cout << "unordered pairs :";
	printPairs(paired_vec);
	if (current.size() % 2 == 1) {
		last_one = *(current.end() - 1);
	}
	std::for_each(paired_vec.begin(), paired_vec.end(), swapIf);
	std::cout << "ordered pairs :";
	printPairs(paired_vec);
	current.clear();
	current.resize(paired_vec.size());
	pend.resize(paired_vec.size());
	std::transform(paired_vec.begin(), paired_vec.end(), current.begin(), getFirst);
	current = _vecMergeSort(current);
	std::vector<int> to_return;
	for (int_it it = current.begin(); it != current.end(); ++it) {
		to_return.push_back(get_pending_number(paired_vec, *it));	
	}
	if (last_one != -1) {
		to_return.push_back(last_one);
	}
	for (int_it it = current.begin(); it != current.end(); ++it) {
		to_return.push_back(*it);	
	}
	printVec(to_return);
	return (to_return);
}
