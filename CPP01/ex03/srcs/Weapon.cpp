/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:39:46 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 19:40:01 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type): type(type) {
	return ;
}

Weapon::~Weapon( void ) {
	return ;
}

const std::string	Weapon::getType( void ) const {
	return(this->type);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
	return ;
}
