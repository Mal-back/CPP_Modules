/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:02:58 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/02 16:02:59 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook( int _next_contact ) : _next_contact_to_write(_next_contact) {
	return ;
}

PhoneBook::~PhoneBook( void ) {
	return ;
}

void	PhoneBook::add_contact(void) {
	if (_temporary_contact.fetch_contact() == 0)
		return ;
	_contact_entries[_next_contact_to_write].copy_contact(_temporary_contact);
	_next_contact_to_write == 7 ? _next_contact_to_write = 0: ++_next_contact_to_write;
}

void	PhoneBook::_padded_display(std::string info) const {
	if (info.size() < 10) {
		std::cout << std::setw(10) << info << "|";
	}
	else {
		info.erase(9);
		std::cout << info << "." << "|";
	}
}

void	PhoneBook::_get_entry_to_display( void ) const {
	std::string	user_input;
	int					index = 0;

	std::cout << "Enter the index of the contact you whish to display : ";
	std::getline(std::cin, user_input);
	std::istringstream(user_input) >> index;
	if (index < 1 || index > 8) {
		std::cout << "Invalid index. Aborting" << std::endl;
	}
	else if (_contact_entries[index - 1].is_set != 1) {
		std::cout << "Asked index isn't set. Aborting" << std::endl;
	}
	else {
		_contact_entries[index - 1].display_contact();
	}
	return ;
}

void	PhoneBook::display_contact_list( void ) const {
	std::string contact_info;	
	int					i = 0;

	if (_contact_entries[i].is_set == 0) {
		std::cout << "No contact set-up yet. Please try again after adding at\
 least one contact to the phonebook" << std::endl;
		return ;
	}
	std::cout << std::setw(11) << "Index|"  << std::setw(11) << "First Name|"  
		<< std::setw(11) << "Last Name|"  
		<< std::setw(11) << "Nickname|" << std::endl;
	while (_contact_entries[i].is_set != 0 && i < 8)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		contact_info = _contact_entries[i].first_name;
		_padded_display(contact_info);
		contact_info = _contact_entries[i].last_name;
		_padded_display(contact_info);
		contact_info = _contact_entries[i].nick_name;
		_padded_display(contact_info);
		std::cout << std::endl;
		++i;
	}
	_get_entry_to_display();
	return ;
}
