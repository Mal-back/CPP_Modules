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

int main()
{
Weapon club = Weapon("crude spiked club");
Weapon club2 = Weapon("crude spiked club");
HumanA bob("Bob", club);
HumanB jim("Jim");
bob.attack();
club.setType("some other type of club");
bob.attack();
jim.setWeapon(club2);
jim.attack();
club2.setType("some other type of club");
jim.attack();
return 0;
}
