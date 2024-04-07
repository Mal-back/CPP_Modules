/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:20:04 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/07 18:20:26 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _xCoordinate( 0 ), _yCoordinate( 0 ) {
	return ;
}

Point::Point( float x, float y) : _xCoordinate( x ), _yCoordinate( y ) {
	return ;
}

Point::Point( Point const& to_copy ) : _xCoordinate(to_copy.getX()), _yCoordinate(to_copy._yCoordinate) {
	return ;
}

Point::~Point( void ) {
	return ;
}

Point& Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		const_cast<Fixed&>(this->_xCoordinate) = rhs._xCoordinate;
		const_cast<Fixed&>(this->_yCoordinate) = rhs._yCoordinate;
	}
	return (*this);
}

Fixed const& Point::getX( void ) const {
	return (this->_xCoordinate);
}

Fixed const& Point::getY( void ) const {
	return (this->_yCoordinate);
}

float	Point::getXAsFloat( void ) const {
	return(this->getX().toFloat());
}

float	Point::getYAsFloat( void ) const {
	return(this->getY().toFloat());
}
