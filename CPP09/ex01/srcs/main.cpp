/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:22:30 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/10 16:22:31 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error : the program should take an expression as argument" << std::endl;
		return (0);
	}
	try {
		RPN rpn(av[1]);
		std::cout << rpn.evaluate() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
