/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poison.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:39:18 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 16:40:19 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POISON_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

# define POISON_HPP

class Poison : public AMateria {
	public :

		Poison( void );
		Poison( Poison const& to_copy);
		~Poison( void );

		Poison&		operator=(const Poison& rhs);

		virtual AMateria*			clone( void ) const;
		virtual	void					use( ICharacter& target) const;
	
};

#endif
