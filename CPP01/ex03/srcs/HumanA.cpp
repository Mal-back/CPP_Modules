/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:51:43 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 19:51:44 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), Current_Weapon(weapon){
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void	HumanA::attack( void ) {
	std::cout << this->name << " attacks with their " << Current_Weapon.getType() << std::endl;
}
