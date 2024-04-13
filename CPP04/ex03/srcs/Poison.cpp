/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poison.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:41:24 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 16:43:48 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poison.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <new>

Poison::Poison( void ): AMateria("poison") {
	return ;
}

Poison::Poison(const Poison& to_copy) : AMateria("poison") {
	(void)to_copy;
	return ;
}

Poison::~Poison ( void ) {
	return ;
}

Poison&		Poison::operator=(const Poison& rhs) {
	(void)rhs;
	return (*this);
}

void	Poison::use( ICharacter& target) const {
	std::cout << "* poisons " << target.getName() <<" *" << std::endl;
	return ;
}

AMateria*	Poison::clone() const {
	AMateria*	new_one = new(std::nothrow) Poison(*this);
	return (new_one);
}
