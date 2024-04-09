/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:57:20 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 17:57:21 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

	public :

		Cat( void );
		Cat( const Cat& to_copy );
		~Cat( void );

		Cat&			operator=(const Cat& rhs);

		virtual void				makeSound( void ) const;	
};

#endif
