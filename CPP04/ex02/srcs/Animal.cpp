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

Animal::Animal( void ) : _type("None"), _brain(new(std::nothrow) Brain){
	std::cout << "Animal default constructor Called" << std::endl;
	// Uncomment the line below to check for mempry leaks.
	//Of course , i will cause memory leaks.
	// this->_brain = NULL;
	return ;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor Called" << std::endl;
	if (_brain != NULL) { delete _brain; }
	return ;
}

Animal::Animal(const Animal& to_copy): _brain(new(std::nothrow) Brain()){
	std::cout << "Animal copy constructor Called" << std::endl;
	if (this->_brain != NULL) { (*this->_brain = *to_copy._brain); }
	this->_type = to_copy.getType();
	return ;
}

Animal&		Animal::operator=(Animal const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs.getType();
		if (this->_brain != NULL) { *this->_brain = *rhs._brain; }
	}
	std::cout << "Animal equal operator overload Called" << std::endl;
	return (*this);
}

bool	Animal::getBrainIntegrity( void ) const {
	if (this->_brain == NULL) {
		return (false);
	} else {
		return (true);
	}
}

void	Animal::printBrainAdress( void ) const {
	std::cout << "My brain live at adress : " << &this->_brain << " !" <<std::endl;
}

const std::string&	Animal::getType( void ) const {
	return (this->_type);
}
