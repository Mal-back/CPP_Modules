/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:29:33 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/28 18:29:33 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template<typename T>
Array<T>::Array( void ) : _size(0) {
	try {
		this->_array = new T[0];
	} catch (std::exception& e) {
		this->_array = NULL;
	} return ;
}

template<typename T>
Array<T>::Array( unsigned int n ) : _size(n) {
	try {
		this->_array = new T[this->size()];
	} catch (std::exception& e) {
		this->_array = NULL;
		return ;
	}
}

template<typename T>
Array<T>::Array( const Array<T>& to_copy ) : _size(to_copy.size()) {
	try {
		this->_array = new T[this->size()];
	} catch (std::exception& e) {
		this->_array = NULL;
		return ;
	}
	for (unsigned int i = 0; i < this->size(); ++i) {
		this->_array[i] = to_copy[i];
	} return ;  
}

template<typename T>
Array<T>::~Array( void ) {
	if (this->_array != NULL) {
		delete [] this->_array;
	} return ;
}
template<typename T>
Array<T>&		Array<T>::operator=(const Array<T>& rhs) {
	if (*this != &rhs) {
		if (this->_array != NULL) {delete [] this->_array;};
		try {
			this->_array = new T[rhs->size()];
			static_cast<unsigned int>(this->size) = rhs.size();
		} catch (std::exception& e) {
			this->_array = NULL;
			return ;
		}
		for (unsigned int i = 0; i < this->size(); ++i) {
			this[i] = rhs[i];
		}
	} return (*this);
}

template< typename T>
T&		Array<T>::operator[](const unsigned int n) const{
	if (n < 0 || n >= this->size()) {
		throw outOfBounds();
	} return (this->_array[n]);
}

template< typename T>
const char*	Array<T>::outOfBounds::what() const throw() {
	return ("Exception : Asked index is out of index bounds");
}

template<typename T>
unsigned int Array<T>::size( void ) const{
	return (this->_size);
}

template<typename T>
bool	Array<T>::getArrayIntegrity( void ) const {
	if (this->_array == NULL) {return (false);} 
	return (true);
}
