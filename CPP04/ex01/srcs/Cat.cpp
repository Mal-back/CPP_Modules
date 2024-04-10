/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:38 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 17:59:57 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor Called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor Called" << std::endl;
	// if (_brain != NULL) { delete _brain; }
	return ;
}

Cat::Cat(const Cat& to_copy) : Animal() {
	std::cout << "Cat copy constructor Called" << std::endl;
	this->_type = to_copy._type;
	if (this->_brain != NULL) { *this->_brain = *to_copy._brain; }
	return ;
}

Cat&		Cat::operator=(Cat const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs._type;
		if (this->_brain != NULL) { *this->_brain = *rhs._brain; }
	}
	std::cout << "Cat equal operator overload Called" << std::endl;
	return (*this);
}

void		Cat::makeSound( void ) const {
	std::cout << "Meooooooooow !" << std::endl;
	return ;
}
