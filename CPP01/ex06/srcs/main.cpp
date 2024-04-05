/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:13:09 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/05 13:13:12 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int ac, char **av ) {
	const	char* levels_init[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (ac != 2) {
		std::cout << "Invalid number of arguments(expected 1)" << std::endl;
		return (0);
	}
	Harl	harl(levels_init);

	harl.complain(av[1]);
	return (0);
}
