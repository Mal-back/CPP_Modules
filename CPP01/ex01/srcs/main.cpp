/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:08:06 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 17:08:07 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*horde1 = NULL;
	Zombie	*horde2 = NULL;
	Zombie	*horde3 = NULL;
	std::cout << "Creating a horde of 42 zombies" << std::endl;
	horde1 = zombieHorde(42, "Students");
	for (int i = 0; i < 42; ++i) {
		horde1[i].announce();
	}
	std::cout << "Creating a horde of 21 zombies" << std::endl;
	horde2 = zombieHorde(21, "Ugly_guys");
	for (int i = 0; i < 21; ++i) {
		horde2[i].announce();
	}
	std::cout << "Creating a horde of -4 zombies" << std::endl;
	horde3 = zombieHorde(-4, "Students");
	delete [] horde1;
	delete [] horde2;
	return 0;
}
