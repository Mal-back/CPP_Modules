/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:42:06 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/09 15:42:07 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <list>
#include <mutantStack.hpp>
#define ANNOUNCE "\033[1;31m"
#define RESET "\033[0m"

int	main( void ) {
{
	std::cout << ANNOUNCE << " ------ Subject Test : ----------" << RESET
		<< std::endl << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}
{
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << " ------ Subject Test with a list : ----------" << RESET
		<< std::endl << std::endl << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}
{
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << " ------ Custom test : Copy Constructor and assignement operator----------" << RESET
		<< std::endl << std::endl << std::endl;
	MutantStack<int> ms;
	ms.push(4);
	ms.push(45);
	ms.push(22);
	ms.push(42);
	ms.push(56);
	ms.push(221);
	MutantStack<int> ms2(ms);
	MutantStack<int> ms3 = ms;
	std::cout << ANNOUNCE << " ------ First Stack ----------" << RESET
		<< std::endl;
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << ANNOUNCE << " ------ Copied Stack ----------" << RESET
		<< std::endl;
	for (MutantStack<int>::iterator it = ms2.begin(); it != ms2.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << ANNOUNCE << " ------ Assigned Stack ----------" << RESET
		<< std::endl;
	for (MutantStack<int>::iterator it = ms3.begin(); it != ms3.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
{
	std::cout << std::endl << std::endl;
	std::cout << ANNOUNCE << " ------ Custom test : Reverse iterator ----------" << RESET
		<< std::endl << std::endl << std::endl;
	MutantStack<int> ms;
	srand(time(NULL));
	for(int i = 0; i < 14; ++i) {
		ms.push(rand() / 10000000);
	}
	std::cout << ANNOUNCE << " ------ Printing with classic iterators ----------" << RESET
		<< std::endl;
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << ANNOUNCE << " ------ Printing with reverse iterators ----------" << RESET
		<< std::endl;
	for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it) {
		std::cout << *it << std::endl;
	}
}
}
