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
		return ;
	}
	for (unsigned int i = 0; i < to_copy._getSize(); ++i) {
		this->_array[i] = to_copy._array[i];
	}
	this->_longestSpan = to_copy.longestSpan();
	this->_shortestSpan = to_copy.shortestSpan();
	return ;
}

Span::~Span( void ) {
	delete [] this->_array;
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
	this->_longestSpan = rhs.longestSpan();
	this->_shortestSpan = rhs.shortestSpan();
	return (*this);
}

const char 		*Span::notEnoughMember::what() const throw() {
	return ("Not enough Member to find a span");
}

const char 		*Span::fullSpan::what() const throw() {
	return ("This span class is full");
}

unsigned int	Span::_getSize( void ) const {
	return (this->_size);
}

unsigned int	Span::_getLength( void ) const {
	return (this->_length);
}

unsigned int	Span::shortestSpan( void ) const {
	return (this->_shortestSpan);
}

unsigned int	Span::longestSpan( void ) const {
	return (this->_longestSpan);
}

unsigned int	Span::_getPos( unsigned int to_place ) const {
	unsigned int	i;
	for (i = 0; i < this->_getSize() && this->_array[i] < to_place; ++i) {}
	return (i);
}

void	Span::_insert(unsigned int pos, unsigned int to_insert) {
	unsigned int	temp1 = _array[pos];
	unsigned int	temp2;

	_array[pos] = to_insert;
	++pos;
	for(int i = pos; i < this->_getSize() - 1; ++i) {
		temp2 = this->_array[pos + 1];
	}
}
