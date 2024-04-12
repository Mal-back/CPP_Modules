/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:42:46 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/11 18:42:46 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

# define AMATERIA_HPP

class AMateria {

	public :

		AMateria( void );
		AMateria( std::string const& type);
		AMateria( AMateria const& to_copy);	
		virtual ~AMateria( void );

		AMateria&		operator=(const AMateria& rhs);

		const std::string&		getType( void ) const;
		virtual AMateria*			clone( void ) const = 0;
		virtual	void					use( ICharacter& target) const;

	protected :

		void	_setType(const std::string& rhs);
		const std::string _type;

} ;

#endif
