/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:38:53 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 17:38:53 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

#include "Brain.hpp"

# define ANIMAL_HPP

class Animal {

	public :

		Animal( void );
		Animal( const Animal& to_copy );
		virtual ~Animal( void );

		Animal&			operator=(const Animal& rhs);

		virtual void				makeSound( void ) const = 0;	
		const std::string&	getType( void ) const;
		bool								getBrainIntegrity( void ) const ;
		void								printBrainAdress( void ) const;
		virtual void				set_idea( const std::string& new_idea ) const = 0;
		virtual void				print_idea( int n ) const = 0;
		virtual void				print_idea_list( void ) const = 0;

	protected :

		std::string			_type;
		Brain*					_brain;
};

#endif
