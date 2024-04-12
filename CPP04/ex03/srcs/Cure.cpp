/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:26:34 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/12 18:26:35 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <new>

Cure::Cure( void ): AMateria("cure") {
	return ;
}

Cure::Cure(const Cure& to_copy) : AMateria("cure") {
	return ;
}

Cure::~Cure ( void ) {
	return ;
}

Cure&		Cure::operator=(const Cure& rhs) {
	return (*this);
}

void	Cure::use( ICharacter& target) const {
	std::cout << "* heals " << target.getName() <<"’s wounds *" << std::endl;
	return ;
}

AMateria*	Cure::clone() const {
	AMateria*	new_one = new(std::nothrow) Cure(*this);
	return (new_one);
}
