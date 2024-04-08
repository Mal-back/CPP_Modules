/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:08:48 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 18:08:49 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {
	ScavTrap scavtrap("ScavTrap");
	ClapTrap claptrap("ClapTrap");

	scavtrap.guardGate();
	scavtrap.attack("ClapTrap");
	claptrap.takeDamage(30);
	scavtrap.beRepaired(52);
	scavtrap.takeDamage(15);
	return (0);
}
