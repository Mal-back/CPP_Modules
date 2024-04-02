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
#include <cstdlib>
#include "main.hpp"

void display_help(void)
{
	std::cout << "Unknown action. Availables actions are :"<< std::endl;
	std::cout << "ADD : Save a new contact." << std::endl;
	std::cout << "SEARCH : Display the information of a contact." << std::endl;
	std::cout << "EXIT : exit the program." << std::endl;
}

void	parse_input(std::string user_input, PhoneBook& phonebook)
{
	if (user_input.compare("EXIT") == 0) {
		exit(EXIT_SUCCESS);
	}
	else if (user_input.compare("ADD") == 0) {
		phonebook.add_contact();
	}
	else if (user_input.compare("SEARCH") == 0) {
		phonebook.display_contact_list();	
	}
	else {
		display_help();
	}
	if (std::cin.eof()) {
		exit(EXIT_SUCCESS);
	} 
	return ;
}

int	main(void) {
	PhoneBook		phonebook(0);
	std::string	user_input;

	std::cout << "Enter a command : ";
	while (std::getline(std::cin, user_input)) {
		parse_input(user_input, phonebook);
		user_input.clear();
		std::cout << "Enter a command : ";
	}
	std::cout << std::endl;
	return 0;
}
