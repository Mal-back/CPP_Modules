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

void	delete_horde(Zombie **horde) {
	for (int i = 0; i < 3; i++) {
		if (horde[i] != NULL) {
			delete [] horde[i];
		}
	}
}

void print_horde(Zombie *horde, int horde_size) {
	for (int i = 0; i < horde_size; ++i) {
		horde[i].announce();
	}
}

int	main(void) {
	Zombie	*horde[3] = { NULL };

	std::cout << "Creating a horde of 42 zombies" << std::endl;
	horde[0] = zombieHorde(42, "Students");
	if (horde[0] == NULL) { return (1); }
	print_horde(horde[0], 42);


	std::cout << "Creating a horde of 21 zombies" << std::endl;
	horde[1] = zombieHorde(21, "Ugly_guys");
	if (horde[1] == NULL) {
		delete_horde(horde);
		return (1);
	}
	print_horde(horde[1], 21);

	std::cout << "Creating a horde of -4 zombies" << std::endl;
	horde[2] = zombieHorde(-4, "Students");
	delete_horde(horde);

	return 0;
}
