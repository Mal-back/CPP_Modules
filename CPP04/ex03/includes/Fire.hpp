/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:39:13 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 16:39:33 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

# define FIRE_HPP

class Fire : public AMateria {
	public :

		Fire( void );
		Fire( Fire const& to_copy);
		~Fire( void );

		Fire&		operator=(const Fire& rhs);

		virtual AMateria*			clone( void ) const;
		virtual	void					use( ICharacter& target) const;
	
};

#endif
