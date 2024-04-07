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
#include <cmath>
#include <ostream>

const int	Fixed::_fractionalSize = 8;

Fixed::Fixed( void ): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int number ) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = number << _fractionalSize;
	return ;
}

Fixed::Fixed( float const number ) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(number * (1 << _fractionalSize));
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

int		Fixed::toInt( void ) const {
	return (_rawBits >> _fractionalSize);
}

float		Fixed::toFloat( void ) const {
	return (static_cast<float>(_rawBits) / static_cast<float>(1 << _fractionalSize));
}

void	Fixed::setRawBits( const int raw) {
	this->_rawBits = raw;
	return ;
}

int	Fixed::getRawBits( void ) const {
	return(this->_rawBits);
}

Fixed&			Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_rawBits = rhs._rawBits;
	}
	return (*this);
}

std::ostream&		operator<<(std::ostream& o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool	Fixed::operator<(Fixed const& rhs) {
	if (this->_rawBits < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const& rhs) {
	if (this->_rawBits <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(Fixed const& rhs) {
	if (this->_rawBits > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const& rhs) {
	if (this->_rawBits >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const& rhs) {
	if (this->_rawBits == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const& rhs) {
	if (this->_rawBits != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const& rhs) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const& rhs) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const& rhs) {
	Fixed res;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++( void ) {
	this->_rawBits += 1;
	return (*this);
}

Fixed&	Fixed::operator--( void ) {
	this->_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed copy(*this);
	this->_rawBits -= 1;
	return (copy);
}

Fixed	Fixed::operator++( int ) {
	Fixed copy(*this);
	this->_rawBits += 1;
	return (copy);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a <= b) {
		return (a);
	} else {
		return (b);
	}
}

const Fixed&	Fixed::min(Fixed const& a, Fixed const& b) {
	if (a.getRawBits() <= b.getRawBits()) {
		return (a);
	} else {
		return (b);
	}
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a >= b) {
		return (a);
	} else {
		return (b);
	}
}

const Fixed&	Fixed::max(Fixed const& a, Fixed const& b) {
	if (a.getRawBits() >= b.getRawBits()) {
		return (a);
	} else {
		return (b);
	}
}
