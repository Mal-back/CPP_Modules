/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:02:19 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/04 15:02:19 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Substitute.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Substitute: error: Invalid number\
of arguments(expected 3)" << std::endl;
		return (0);
	}
	Substitute substitute(av[1], av[2], av[3]);
	if (substitute.init_streams() != 0) {
		return (1);
	}
	substitute.substitute_buffer();
	return (0);
}
