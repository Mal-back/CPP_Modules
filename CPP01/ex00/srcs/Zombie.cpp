/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:47:11 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 16:47:12 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has been destroyed" << std::endl;
	return;
}

void	Zombie::announce(void) const{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
