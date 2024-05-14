/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:27:58 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/07 15:27:58 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>
#include <cstdlib>
#include <iostream>
#define ANNOUNCE "\033[1;31m"
#define RESET "\033[0m"

int main( void ) {
	std::cout << ANNOUNCE << "--------- Subject Main ---------" << std::endl << std::endl << RESET;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << "--------- Range iterator with an array of 10 ---------" << std::endl << std::endl << RESET;
	Span sp2(10);
	sp2.addNumber(0, 10);
	std::cout << "Shortest Span : " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span : " << sp2.longestSpan() << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << "--------- Range iterator with an array of 500k ---------" << std::endl << std::endl << RESET;
	Span sp3(500000);
	sp3.addNumber(0, 500000);
	std::cout << "Shortest Span : " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest Span : " << sp3.longestSpan() << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << "--------- Different exceptions ---------" << std::endl << std::endl << RESET;
	try {
		sp3.addNumber(5);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Span sp4(5);
	try {
		std::cout << "Shortest Span : " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp4.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Span sp5(0);
	try {
		sp5.addNumber(4);
		std::cout << "Shortest Span : " << sp5.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp5.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Span sp6(15);
	try {
		sp6.addNumber(10, 5);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << "--------- Array filled with random numbers ---------" << std::endl << std::endl << RESET;
	Span random(12);
	srand(time(NULL));
	for (int i = 0; i < 12; ++i) {
		random.addNumber(rand() / 10000000);
	}
	random.printArr();
	std::cout << std::endl << "Shortest Span : " << random.shortestSpan() << std::endl;
	std::cout << "Longest span : " << random.longestSpan() << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << "--------- Sorted array for verification ---------" << std::endl << std::endl << RESET;
	random.printArr();
	return 0;
}
