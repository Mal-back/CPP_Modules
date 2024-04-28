/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:06:18 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/28 18:06:18 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <Array.hpp>
#include <Array2.hpp>

int main( void ) {
	Array<int> int_arr(12);
	std::cout << "Normal behavior and deep copies with int arrays :" << std::endl;
	if (int_arr.getArrayIntegrity() == false) {return (1);}
	for (unsigned int i = 0; i < int_arr.size(); ++i) {
		std::cout << int_arr[i] << std::endl;
	}
	for (unsigned int i = 0; i < int_arr.size(); ++i) {
		int_arr[i] = i;
	}
	for (unsigned int i = 0; i < int_arr.size(); ++i) {
		std::cout << int_arr[i] << std::endl;
	}
	Array<int> int_arr2(int_arr);
	if (int_arr.getArrayIntegrity() == false) {return (1);}
	for (unsigned int i = 0; i < int_arr2.size(); ++i) {
		int_arr2[i] = i * 2;
	}
	for (unsigned int i = 0; i < int_arr.size(); ++i) {
		std::cout << int_arr[i] << std::endl;
	}
	for (unsigned int i = 0; i < int_arr2.size(); ++i) {
		std::cout << int_arr2[i] << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Testing out of bounds indexing :" << std::endl;
	try {
		std::cout << int_arr[int_arr.size() + 1] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Array<std::string> str_arr(6);
	if (str_arr.getArrayIntegrity() == false) {return (1);}
	std::string s = "Hello";
	for (unsigned int i = 0; i < str_arr.size(); ++i) {
		str_arr[i] = s;
		s += "World ! ";
	}
	for (unsigned int i = 0; i < str_arr.size(); ++i) {
		std::cout << str_arr[i] << std::endl;
	}
	return (0);
}
