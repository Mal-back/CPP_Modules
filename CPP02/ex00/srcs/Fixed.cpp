/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:03:17 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/05 18:03:18 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_number_of_bits = 8;

Fixed::Fixed( void ): _raw_bits(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & to_copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Fixed::setRawBits( const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_bits = raw;
	return ;
}

Fixed &			Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs) {
		this->_raw_bits = rhs._raw_bits;
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_raw_bits);
}
