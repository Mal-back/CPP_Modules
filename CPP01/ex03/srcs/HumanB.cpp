/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:00:50 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 20:00:51 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {
	this->_current_Weapon = NULL;
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::attack( void ) {
	std::cout << this->_name << " attacks with their "; 
	if (this->_current_Weapon != NULL) {
		std::cout << _current_Weapon->getType();
	} else {
		std::cout << "Bare hands";
	}
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon) {
	this->_current_Weapon = &new_weapon;
	return ;
}
