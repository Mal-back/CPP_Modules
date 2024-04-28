/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:22:53 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/28 18:22:53 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

# define ARRAY_HPP

#include <exception>
template<typename T>
class Array {
	public :

		Array<T>( void );
		Array<T>( unsigned int n);
		Array<T>(const Array& to_copy);
		~Array<T>( void );

		Array<T>&		operator=(const Array<T>& rhs);
		T&					operator[](const unsigned int n) const;

		unsigned int	size( void ) const;
		bool					getArrayIntegrity( void ) const;

		class outOfBounds : public std::exception {
			
			public :

				virtual const char* what() const throw();
		} ;

	private:

		const unsigned int 	_size;
		T	*									_array;

};

# endif
