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

int	main( void ) {
	const	char* levels_init[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl	harl(levels_init);

	std::cout << "Harl complain will be called to Debug level :" << std::endl;
	harl.complain("DEBUG");
	std::cout << "Harl complain will be called to Info level :" << std::endl;
	harl.complain("INFO");
	std::cout << "Harl complain will be called to Warning level :" << std::endl;
	harl.complain("WARNING");
	std::cout << "Harl complain will be called to Error level :" << std::endl;
	harl.complain("ERROR");
	return (0);
}
