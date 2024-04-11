/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:48:18 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 17:48:19 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("None") {
	std::cout << "Animal default constructor Called" << std::endl;
	return ;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor Called" << std::endl;
	return ;
}

Animal::Animal(const Animal& to_copy) {
	std::cout << "Animal copy constructor Called" << std::endl;
	this->_type = to_copy.getType();
	return ;
}

Animal&		Animal::operator=(Animal const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	std::cout << "Animal equal operator overload Called" << std::endl;
	return (*this);
}

void		Animal::makeSound( void ) const {
	std::cout << "Random animal noise (probably a unicorn)" << std::endl;
	return ;
}

const std::string&	Animal::getType( void ) const {
	return (this->_type);
}
