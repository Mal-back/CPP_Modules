/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:06:23 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/02 16:06:24 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <cstring>
#include "main.hpp"

void display_help(void)
{
	std::cout << "Unknown action. Availables actions are :"<< std::endl;
	std::cout << "ADD : Save a new contact." << std::endl;
	std::cout << "SEARCH : Display the information of a contact." << std::endl;
	std::cout << "EXIT : exit the program." << std::endl;
}

void	parse_input(int	*run_loop, std::string user_input, PhoneBook& phonebook)
{
	if (user_input.compare("EXIT") == 0) {
		*run_loop = 0;
	}
	else if (user_input.compare("ADD") == 0) {

	}
	else if (user_input.compare("SEARCH") == 0) {
	
	}
	else {

	}
	return ;
}

int	main(void) {
	PhoneBook		phonebook;
	std::string	user_input;
	int					run_loop = 1;

	while (run_loop == 1) {
		std::cout << "Enter a command :";
		std::cin >> user_input;
		parse_input(&run_loop, user_input, phonebook);
	}
	return 0;
}
