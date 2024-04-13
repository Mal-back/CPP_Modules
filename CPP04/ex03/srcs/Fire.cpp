/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:41:27 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 16:41:41 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <new>

Fire::Fire( void ): AMateria("fire") {
	return ;
}

Fire::Fire(const Fire& to_copy) : AMateria("fire") {
	(void)to_copy;
	return ;
}

Fire::~Fire ( void ) {
	return ;
}

Fire&		Fire::operator=(const Fire& rhs) {
	(void)rhs;
	return (*this);
}

void	Fire::use( ICharacter& target) const {
	std::cout << "* shoots a fireball at " << target.getName() <<" *" << std::endl;
	return ;
}

AMateria*	Fire::clone() const {
	AMateria*	new_one = new(std::nothrow) Fire(*this);
	return (new_one);
}
