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
#include <bits/types/struct_timeval.h>
#include <string>
#include <sys/time.h>
#include <cerrno>
#include <climits>
#include <cstdlib>

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

void	PmergeMe::vectorSort(char **numbers, int ac) {
	double	number;
	char	*endptr;
	struct timeval tb, te;

	gettimeofday(&tb, NULL);
	this->_intVect.resize(ac);
	for(size_t i = 0; i < ac; ++i) {
		number = std::strtod(numbers[i], &endptr);
		if (errno == ERANGE || number < 0 || number > INT_MAX || *endptr != '\0') {
			throw wrongInput();
		} 
		this->_intVect[i] = number;
	}
}

void PmergeMe::_vecMergeSort( std::vector<int>& current ) {
	if (current.size() == 1) {
	}	else if (current.size() == 2) {
		if (current[0] > current[1]) {
			const int tmp = current[0];
			current[0] = current[1];
			current[1] = tmp;
		} return ;
	}
	std::vector<int> vec1, vec2;
	vec1.resize(current.size() / 2); vec2.resize(current.size() / 2);
	for (size_t i = 0; i < current.size() / 2; ++i) {
		vec1[i] = current[i];	
	}
	for (size_t i = current.size() / 2, idx = 0; i < current.size(); ++i, ++idx) {
		vec2[idx] = current[i];
	}
	this->_vecMergeSort(vec1); this->_vecMergeSort(vec2);
	for (size_t i = 0; vec1.size() != 0 || vec2.size() != 0; ++i) {
		if (vec2.size() == 0 || vec1[0] < vec2[0]) {
			current[i] = vec1[0]; 
			vec1.erase(vec1.begin());
		} else {
			current[i] = vec2[0];
			vec2.erase(vec2.begin());
		}
	}
	return ;
}
