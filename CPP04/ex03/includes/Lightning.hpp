/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lightning.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:39:29 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 16:40:51 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTNING_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

# define LIGHTNING_HPP

class Lightning : public AMateria {
	public :

		Lightning( void );
		Lightning( Lightning const& to_copy);
		~Lightning( void );

		Lightning&		operator=(const Lightning& rhs);

		virtual AMateria*			clone( void ) const;
		virtual	void					use( ICharacter& target) const;
	
};

#endif
