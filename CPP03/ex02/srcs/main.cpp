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
#include "FragTrap.hpp"

int	main( void ) {
	ScavTrap	scavtrap("ScavTrap");
	ClapTrap	claptrap("ClapTrap");
	FragTrap	fragtrap("FragTrap");

	claptrap.printStat();
	scavtrap.printStat();
	fragtrap.printStat();
	scavtrap.guardGate();
	fragtrap.highFiveGuys();
	scavtrap.attack("ClapTrap");
	claptrap.takeDamage(20);
	claptrap.takeDamage(30);
	fragtrap.attack("ScavTrap");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(52);
	scavtrap.attack("FragTrap");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(20);
	return (0);
}
