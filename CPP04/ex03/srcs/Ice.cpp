/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:25:37 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/12 19:25:38 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <new>

Ice::Ice( void ): AMateria("ice") {
	return ;
}

Ice::Ice(const Ice& to_copy) : AMateria("ice") {
	return ;
}

Ice::~Ice ( void ) {
	return ;
}

Ice&		Ice::operator=(const Ice& rhs) {
	return (*this);
}

void	Ice::use( ICharacter& target) const {
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
	return ;
}

AMateria*	Ice::clone() const {
	AMateria*	new_one = new(std::nothrow) Ice(*this);
	return (new_one);
}
