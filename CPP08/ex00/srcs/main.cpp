/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:49:13 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/06 16:49:13 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <easyFind.hpp>
#include <list>
#include <vector>

int main(void) {
	std::vector<int> myvec;
	myvec.push_back(4);
	myvec.push_back(59);
	myvec.push_back(89);
	myvec.push_back(21);
	myvec.push_back(144);
	myvec.push_back(25);
	std::list<int> my_list;
	my_list.push_back(4);
	my_list.push_back(59);
	my_list.push_back(89);
	my_list.push_back(21);
	my_list.push_back(144);
	my_list.push_back(25);
	std::deque<int> my_queue;
	my_queue.push_back(4);
	my_queue.push_back(59);
	my_queue.push_back(89);
	my_queue.push_back(21);
	my_queue.push_back(144);
	my_queue.push_back(25);
	try {
		std::vector<int>::iterator it = easyFind(myvec, 25);
		std::cout << "Occurence found at position " << it - myvec.begin() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::deque<int>::iterator it = easyFind(my_queue, 25);
		std::cout << "Occurence found at position " << it - my_queue.begin() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator it = easyFind(my_list, 25);
		std::cout << "Occurence found at position " << std::distance(my_list.begin(), it) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyFind(myvec, -25);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyFind(my_queue, -25);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyFind(my_list, -25);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} return (0);
}
