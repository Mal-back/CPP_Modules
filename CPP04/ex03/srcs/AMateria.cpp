/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:32:36 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/12 17:32:37 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ): _type("none") {
	return ;
}

AMateria::AMateria( const std::string& type ): _type(type) {
	return ;
}

AMateria::AMateria(const AMateria& to_copy) : _type(to_copy.getType()) {
	return ;
}

AMateria::~AMateria( void ) {
	return ;
}

AMateria&		AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs) {
		this->_setType(rhs.getType());
	}
	return (*this);
}

void	AMateria::_setType( const std::string& new_type ) {
	static_cast<std::string>(_type) = new_type;
	return ;
}

const std::string&	AMateria::getType( void) const {
	return(this->_type);
}

void	AMateria::use( ICharacter& target) const {
	(void)target;
	return ;
}
