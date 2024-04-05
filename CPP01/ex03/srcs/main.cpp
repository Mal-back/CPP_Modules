/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:03:25 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 20:03:26 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main( void )
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
{
	Weapon	*gun = new(std::nothrow)Weapon("Kalashnikov");
	HumanB	savastano("Savastano");

	if (gun == NULL) {
		return (1);
	}
	savastano.attack();
	savastano.setWeapon(*gun);
	savastano.attack();
	gun->setType("11.43");	
	savastano.attack();
	delete gun;
}
return 0;
}
