/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:12:30 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 15:12:30 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
# include <string>

# define MATERIASOURCE_HPP

class MateriaSource : public IMateriaSource {

	public:

		MateriaSource( void );
		MateriaSource( const MateriaSource& to_copy );
		virtual ~MateriaSource( void );

		MateriaSource&	operator=(const MateriaSource & rhs);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type) const;

	private :

		AMateria*	_knownMateria[4];

		void			_cleanTab( void );
};

#endif
