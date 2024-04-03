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

HumanB::HumanB(std::string name) : name(name) {
	this->Current_Weapon = NULL;
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::attack( void ) {
	std::cout << this->name << " attacks with their " << Current_Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon) {
	this->Current_Weapon = &new_weapon;
	return ;
}
