/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:37:19 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/12 16:37:20 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

# define CURE_HPP

class Cure : public AMateria {
	public :

		Cure( void );
		Cure( Cure const& to_copy);
		~Cure( void );

		Cure&		operator=(const Cure& rhs);

		virtual AMateria*			clone( void ) const;
		virtual	void					use( ICharacter& target) const;
	
};

#endif
