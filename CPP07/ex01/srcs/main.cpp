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
#include <string>

int main( void ) {
	int arr[] = { 42, -42, 78, 5096, -666};
	std::string	str_arr[] = { "Hello", "World", "This", "is", "my first", "string array"};

	iter(arr, sizeof(arr) / sizeof(int), &display);
	iter(str_arr, sizeof(str_arr) / sizeof(std::string), &display);
}
