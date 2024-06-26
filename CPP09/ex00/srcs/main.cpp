/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:24:03 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/09 20:24:04 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bitcoinExchange.hpp>
#include <fstream>
#include <iostream>

int main(int ac, char **av) {
	std::ifstream infile;
	if (ac != 2) {
		std::cout << "Error : no input file" << std::endl;
		return (0);
	}
	infile.open(av[1]);
	if (infile.fail()) {
		std::cout << "Error : could not open file" << std::endl;
		return (0);
	}
	try {
		BitcoinExchange	exchanger;
		exchanger.exchange(infile);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
