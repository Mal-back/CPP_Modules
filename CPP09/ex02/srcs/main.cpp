/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:23:59 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/13 15:24:00 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
	try {
		PmergeMe me;
		me.vectorSort(av + 1, ac - 1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
