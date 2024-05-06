/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:53:10 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 15:53:10 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <iostream>
int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Program should take only one argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
