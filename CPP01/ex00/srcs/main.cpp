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
	Zombie	*Dude = NULL;

	std::cout << "RandomChump is called to create Frankenstein"	<< std::endl;
	randomChump("Frankenstein");
	std::cout << "newZombie is called to create Einstein and return his address" << std::endl;
	Dude = newZombie("Einstein");
	std::cout << "Einstein will now announce itself from main function" << std::endl;
	Dude->announce();
	std::cout << "Einstein will now be destroy from main function" << std::endl;
	delete (Dude);
	return 0;
}
