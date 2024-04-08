/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:55:25 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/07 17:55:26 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

#define POINT_HPP

#include "Fixed.hpp"

class Point {

	public :

		Point( void );
		Point( float x, float y);
		Point( Point const& to_copy);
		~Point( void );

		Point&				operator=(Point const& rhs);

		Fixed const&	getX( void ) const;
		Fixed const&	getY( void ) const;
		float					getXAsFloat( void ) const;
		float					getYAsFloat( void ) const;
		bool					isCoordZero( void ) const;

	private :

		Fixed	const	_xCoordinate;
		Fixed const	_yCoordinate;
} ;

std::ostream	&	operator<<( std::ostream& o, Point const& rhs);

#endif
