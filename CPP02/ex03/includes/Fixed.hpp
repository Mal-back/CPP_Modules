/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:53:53 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/05 17:53:54 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed {

	public:

		Fixed( void );
		Fixed( const int number );
		Fixed( const float number );
		Fixed(Fixed const & to_copy);
		~Fixed( void );

		int									getRawBits( void ) const;
		void								setRawBits( int const raw );
		int									toInt( void ) const;
		float								toFloat( void ) const ;
		static Fixed&				min(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed&				max(Fixed& a, Fixed& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);

		Fixed&				operator=( Fixed const& rhs );
		Fixed					operator+( Fixed const& rhs );
		Fixed					operator-( Fixed const& rhs );
		Fixed					operator*( Fixed const& rhs );
		Fixed					operator/( Fixed const& rhs );
		Fixed&				operator++( void );
		Fixed					operator++( int );
		Fixed&				operator--( void );
		Fixed					operator--( int );
		bool					operator>( Fixed const& rhs );
		bool					operator<( Fixed const& rhs );
		bool					operator>=( Fixed const& rhs );
		bool					operator<=( Fixed const& rhs );
		bool					operator==( Fixed const& rhs );
		bool					operator!=( Fixed const& rhs );

	private:

		static const int	_fractionalSize;
		int								_rawBits;
} ;

std::ostream	&	operator<<( std::ostream& o, Fixed const& rhs);

#endif
