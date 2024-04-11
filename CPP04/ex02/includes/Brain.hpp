/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:02:43 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/10 16:02:44 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

#include <string>
#include <iostream>

# define BRAIN_HPP

class Brain {

	public :

		Brain( void );
		Brain( const Brain& );
		~Brain( void );

		Brain&		operator=( const Brain& rhs );

		void			set_idea( const std::string& new_idea );
		void			print_idea( int n ) const;
		void			print_idea_list( void ) const;

	private :

		std::string	_ideas[100];
		int					_next_idea_to_fill;

		const	std::string&	_get_idea(int n) const;
		int									_get_next_idea_index( void ) const;
		void								_update_idea_index( void );
};

#endif
