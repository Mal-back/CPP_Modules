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
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {
	DiamondTrap monstruosity("Dude");

	monstruosity.printStat();
	monstruosity.attack("TrashCan");
	monstruosity.beRepaired(4);
	monstruosity.takeDamage(12);
	monstruosity.whoAmI();
	monstruosity.guardGate();
	monstruosity.highFiveGuys();

	DiamondTrap random;

	random.printStat();
	random.attack("TrashCan");
	random.beRepaired(4);
	random.takeDamage(12);
	random.whoAmI();
	random.guardGate();
	random.highFiveGuys();

	DiamondTrap	random_copy(random);

	random.printStat();
	random.whoAmI();


	return (0);
}
