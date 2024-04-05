/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:38:41 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/05 12:38:43 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <string>
# include <iostream>

class Harl {

	typedef void	(Harl::*complain_ptr)(void) const;
	public :

		Harl ( const char** levels );
		~Harl (void );

		void	complain(std::string level);

	private :

		const	char**	_levels;
		complain_ptr 	_complain_ptr[4];

		void					_debug( void ) const;
		void					_info( void ) const;
		void					_warning( void ) const;
		void					_error( void ) const;
		void					_irrelevant( void ) const;
} ;

#endif // DEBUG
