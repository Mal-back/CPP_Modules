/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:17:01 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/11 20:17:02 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

# define CHARACTER_HPP

class Character : public ICharacter {

	public :

		Character( void );
		Character(const std::string& name);
		Character(const Character& to_copy);
		virtual ~Character( void );

		Character&	operator=(const Character& to_copy);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private :

		const std::string	_name;
		AMateria*					_materiaTab[4];

		void	_copyMateria(const Character& src);
};

#endif
