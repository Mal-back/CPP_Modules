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
		Fixed(Fixed const & to_copy);
		~Fixed( void );

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );

		Fixed &			operator=( Fixed const & rhs);

	private:

		static const int	_number_of_bits;
		int								_raw_bits;
} ;

#endif
