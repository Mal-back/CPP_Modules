/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substitute.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:11:10 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/04 13:11:10 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSTITUTE_HPP

#define SUBSTITUTE_HPP

# include <fstream>
# include <sstream>
# include <string>
# include <iostream>
#	include <cstring>


class Substitute {

	public :

		Substitute(const char *infile, const char *string_to_find,
				const char *string_to_replace);
		~Substitute( void );

		int	init_streams( void );
		void			substitute_buffer ( void );

	private :

		std::string							_file;
		const std::string				_string_to_find;
		const std::string				_string_to_replace;
		std::ifstream						_instream;
		std::ofstream						_outstream;
		std::stringstream				_buffer;

		int	_init_instream( void );
		int	_init_outstream( void );
} ;

#endif
