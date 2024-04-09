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

# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {

	public :

		Animal( void );
		Animal( const Animal& to_copy );
		~Animal( void );

		Animal&			operator=(const Animal& rhs);

		virtual void				makeSound( void ) const;	

	protected :

		std::string					_type;
};

#endif
