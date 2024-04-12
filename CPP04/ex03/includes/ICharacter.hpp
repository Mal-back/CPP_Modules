/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Icharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:53:44 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/11 19:53:45 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP

#include <string>


# define ICHARACTER_HPP

class AMateria;

class ICharacter
{
	public:

		virtual ~ICharacter() {}


		virtual std::string const & getName() const = 0;
		virtual void 							equip(AMateria* m) = 0;
		virtual void 							unequip(int idx) = 0;
		virtual void 							use(int idx, ICharacter& target) = 0;
};

#endif
