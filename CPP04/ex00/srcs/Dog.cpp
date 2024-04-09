/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:04:29 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:04:52 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor Called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor Called" << std::endl;
	return ;
}

Dog::Dog(const Dog& to_copy) : Animal() {
	std::cout << "Dog copy constructor Called" << std::endl;
	this->_type = to_copy._type;
	return ;
}

Dog&		Dog::operator=(Dog const& rhs) {	
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "Dog equal operator overload Called" << std::endl;
	return (*this);
}

void		Dog::makeSound( void ) const {
	std::cout << "Woof ! Woof ! Woof !" << std::endl;
	return ;
}
