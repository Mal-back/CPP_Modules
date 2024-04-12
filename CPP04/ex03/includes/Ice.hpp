/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:27:34 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/12 16:27:35 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

# define ICE_HPP

class Ice : public AMateria {
	public :

		Ice( void );
		Ice( std::string const& type);
		Ice( Ice const& to_copy);
		~Ice( void );

		Ice&		operator=(const Ice& rhs);

		virtual AMateria*			clone( void ) const;
		virtual	void					use( ICharacter& target) const;
	
};

#endif
