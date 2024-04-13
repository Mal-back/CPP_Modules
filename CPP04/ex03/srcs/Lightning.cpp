/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lightning.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:41:36 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 16:42:55 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lightning.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <new>

Lightning::Lightning( void ): AMateria("lightning") {
	return ;
}

Lightning::Lightning(const Lightning& to_copy) : AMateria("lightning") {
	(void)to_copy;
	return ;
}

Lightning::~Lightning ( void ) {
	return ;
}

Lightning&		Lightning::operator=(const Lightning& rhs) {
	(void)rhs;
	return (*this);
}

void	Lightning::use( ICharacter& target) const {
	std::cout << "* summon lightning on " << target.getName() <<" *" << std::endl;
	return ;
}

AMateria*	Lightning::clone() const {
	AMateria*	new_one = new(std::nothrow) Lightning(*this);
	return (new_one);
}
