/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:00:21 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 18:00:21 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde;

	if (n < 1)
	{
		std::cout << "You can't create a negative horde, sorry" << std::endl;
		return (NULL);
	}
	horde = new Zombie[n];
	for (int i = 0; i < n; ++i) {
		horde[i].set_name(name);
	}	
	return (horde);
}
