/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:03:36 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:03:37 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

	public :

		Dog( void );
		Dog( const Dog& to_copy );
		~Dog( void );

		Dog&			operator=(const Dog& rhs);

		virtual void				makeSound( void ) const;	
};

#endif
