/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:08:09 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/06 18:08:09 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

#include <exception>
class Span {

	public :
		Span( void );
		Span( unsigned int n );
		Span( const Span& to_copy);
		~Span( void );

		Span&			operator=(const Span& rhs);

		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;
		void					addNumber(unsigned int n);
		void					addNumber(unsigned int first, unsigned int last);

		class fullSpan : public std::exception {
			public :
				const char * what() const throw();
		};
		class notEnoughMember : public std::exception {
			public :
				const char * what() const throw();
		};
	private :
		unsigned int				*_array;
		unsigned int				_size;
		unsigned int				_length;
		unsigned int				_longestSpan;
		unsigned int				_shortestSpan;

		unsigned int	_getSize( void ) const;
		unsigned int	_getLength( void ) const;
		unsigned int	_getPos( unsigned int to_place ) const;
		void					_insert(unsigned int pos, unsigned int to_insert);
};

#endif
