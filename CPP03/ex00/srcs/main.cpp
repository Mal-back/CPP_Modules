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

int	main( void ) {
	ClapTrap wall_e("Wall-e");
	ClapTrap robot(wall_e);

	wall_e.attack("Garbage");
	wall_e.takeDamage(5);
	wall_e.takeDamage(15);
	robot.attack("TrashCan");
	wall_e.attack("Garbage");
	wall_e.beRepaired(13);
	robot.beRepaired(4);
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	robot.attack("TrashCan");
	return (0);
}
