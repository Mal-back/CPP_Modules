/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:09:37 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:09:38 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat default constructor Called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor Called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& to_copy) : WrongAnimal(){
	std::cout << "WrongCat copy constructor Called" << std::endl;
	this->_type = to_copy.getType();
	return ;
}

WrongCat&		WrongCat::operator=(WrongCat const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs.getType();
	}
	std::cout << "WrongCat equal operator overload Called" << std::endl;
	return (*this);
}

void		WrongCat::makeSound( void ) const {
	std::cout << "Hi it's me Miaouss from the team rocket lol" << std::endl;
	return ;
}
