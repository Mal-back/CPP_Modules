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
	ScavTrap	scav("Scavy");
	FragTrap	frag("Fraggy");

	monstruosity.printStat();
	scav.printStat();
	frag.printStat();
	monstruosity.attack("TrashCan");
	monstruosity.beRepaired(4);
	monstruosity.takeDamage(12);
	monstruosity.whoAmI();
	monstruosity.guardGate();
	monstruosity.highFiveGuys();
	frag.takeDamage(13);
	frag.beRepaired(4);
	scav.printStat();

	DiamondTrap random;

	random.printStat();
	random.attack("TrashCan");
	random.beRepaired(4);
	random.takeDamage(12);
	random.whoAmI();
	random.guardGate();
	random.highFiveGuys();
	random.printStat();

	DiamondTrap	random_copy(random);

	random.printStat();
	random.whoAmI();
	for (int i = 0; i < 51; ++i) {
		random.beRepaired(4);
	}
	random.printStat();
	return (0);
}
