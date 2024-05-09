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
#include <iostream>

int main(void) {
	try {
		BitcoinExchange	exchanger;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
