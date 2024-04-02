/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:05:11 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/02 16:05:12 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	this->is_set = 0;
	return ;
}

Contact::~Contact( void ) {
	return ;
}

void	Contact::display_contact(void) const {
	std::cout << "First Name : " << this->first_name << std::endl;
	std::cout << "Last Name : " << this->last_name << std::endl;
	std::cout << "Nick Name : " << this->nick_name << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
}

std::string	Contact::fetch_input(std::string to_display, int *is_set) {
	std::string	to_fill;
	std::cout << to_display;
	std::getline(std::cin, to_fill);
	if (to_fill.size() == 0) {
		std::cout << "Empty fields aren't allowed. Aborting" << std::endl;
		*is_set = 0;
	}
	return (to_fill);
}

int	Contact::fetch_contact() {
	this->is_set = 1;
	this->first_name = fetch_input("Enter first name of the contact : ", &this->is_set);
	if (this->is_set == 1) {
		this->last_name = fetch_input("Enter last name of the contact : ", &this->is_set);
	}
	if (this->is_set == 1) {
		this->nick_name = fetch_input("Enter nickname of the contact : ", &this->is_set);
	}
	if (this->is_set == 1) {
		this->phone_number = fetch_input("Enter phone number of the contact : ", &this->is_set);
	}
	if (this->is_set == 1) {
		this->darkest_secret = fetch_input("Enter darkest secret of the contact : ", &this->is_set);
	}
	return (this->is_set);
}

void	Contact::copy_contact(Contact contact_to_copy) {
	this->is_set = 1;
	this->first_name = contact_to_copy.first_name;	
	this->last_name = contact_to_copy.last_name;
	this->nick_name = contact_to_copy.nick_name;
	this->phone_number = contact_to_copy.phone_number;
	this->darkest_secret = contact_to_copy.darkest_secret;
	return ;
}
