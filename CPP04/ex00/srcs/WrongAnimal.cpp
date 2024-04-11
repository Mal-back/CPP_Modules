/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:08:31 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:08:32 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("None") {
	std::cout << "WrongAnimal default constructor Called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor Called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy) {
	std::cout << "WrongAnimal copy constructor Called" << std::endl;
	this->_type = to_copy.getType();
	return ;
}

WrongAnimal&		WrongAnimal::operator=(WrongAnimal const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	std::cout << "Wrong equal operator overload Called" << std::endl;
	return (*this);
}

void		WrongAnimal::makeSound( void ) const {
	std::cout << "Wrong animal sound (probably glados start talking)" << std::endl;
	return ;
}

const std::string&	WrongAnimal::getType( void ) const {
	return (this->_type);
}
