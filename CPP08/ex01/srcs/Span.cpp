/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:04:36 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/06 19:04:36 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span( void ) : _length(0), _size(0) {
	this->_array = NULL;
	return ;
}

Span::Span( unsigned int n ) : _length(n), _size(0) {
	try {
		this->_array = new unsigned int[this->_getLength()];
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		this->_length = 0;
		this->_array = NULL;
		return ;
	}
}

Span::Span(const Span& to_copy) : _length(to_copy._getLength()), _size(to_copy._getSize()) {
	try {
		this->_array = new unsigned int[this->_getLength()];
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		this->_array = NULL;
		this->_length = 0;
		return ;
	}
	for (unsigned int i = 0; i < to_copy._getSize(); ++i) {
		this->_array[i] = to_copy._array[i];
	}
	return ;
}

Span::~Span( void ) {
	if (this->_array != NULL) {
		delete [] this->_array;
	}
	return ;
}

Span&		Span::operator=(const Span& rhs) {
	if (this == &rhs) {
		return (*this);
	} 
	delete [] this->_array;
	this->_length = rhs._getLength();
	try {
		this->_array = new unsigned int[this->_getLength()];
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		this->_array = NULL;
		return (*this);
	}
	for (unsigned int i = 0; i < rhs._getSize(); ++i) {
		this->_array[i] = rhs._array[i];
	}
	return (*this);
}

const char 		*Span::notEnoughMember::what() const throw() {
	return ("Not enough Member to find a span");
}

const char 		*Span::fullSpan::what() const throw() {
	return ("This span class is full");
}

const char 		*Span::wrongRange::what() const throw() {
	return ("Range order is ambiguous");
}

unsigned int	Span::_getSize( void ) const {
	return (this->_size);
}

unsigned int	Span::_getLength( void ) const {
	return (this->_length);
}

unsigned int	Span::shortestSpan( void ) const {
	if (this->_getSize() < 2 || this->_array == NULL) {
		throw notEnoughMember();
	}
	std::sort(this->_array, this->_array + this->_getSize());
	unsigned int shortest = this->_array[1] - this->_array[0];
	for (unsigned int i = 1; i < this->_getSize() - 1; ++i) {
		if (this->_array[i + 1] - this->_array[i] < shortest) {
			shortest = this->_array[i + 1] - this->_array[i];
		}
	}
	return (shortest);
}

unsigned int	Span::longestSpan( void ) const {
	if (this->_getSize() < 2 || this->_array == NULL) {
		throw notEnoughMember();
	}
	std::sort(this->_array, this->_array + this->_getSize());
	return (this->_array[this->_getSize() - 1] - this->_array[0]);
}

void	Span::addNumber(unsigned int n) {
	if (this->_getSize() == this->_getLength() || this->_array == NULL) {
		throw fullSpan();
	}
	this->_array[this->_getSize()] = n;
	this->_incrementSize();
	return ;
}

void	Span::addNumber(unsigned int start, unsigned int end) {
	if (end <= start) {
		throw wrongRange();
	} else if ( end - start > this->_getLength() - this->_getSize() || this->_array == NULL) {
		throw fullSpan();
	}
	for (unsigned int i = start; i < end; ++i) {
		this->_array[this->_getSize()] = start;
		++start;
		this->_incrementSize();
	}
	return ;
}

void	Span::_incrementSize( void ) {
	++this->_size;
	return ;
}

void	Span::printArr( void ) const {
	for (unsigned int i = 0; i < this->_getSize(); ++i) {
		std:: cout << this->_array[i] << std::endl;
	}
	std::cout << std::endl;
}
