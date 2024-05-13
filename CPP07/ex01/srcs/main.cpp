/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:33:26 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/28 17:33:27 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Iter.hpp>
#include <iostream>
#include <string>

void	display_int(const int& elem) {
	std::cout << elem << std::endl;
}

void	display_str(const std::string& elem) {
	std::cout << elem << std::endl;
}

int main( void ) {
	int arr[] = { 42, -42, 78, 5096, -666};
	std::string	str_arr[] = { "Hello", "World", "This", "is", "my first", "string array"};

	iter(arr, sizeof(arr) / sizeof(int), &display_int);
	iter(str_arr, sizeof(str_arr) / sizeof(std::string), &display_str);
}
