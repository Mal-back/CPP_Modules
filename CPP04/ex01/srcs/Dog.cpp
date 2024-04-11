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
	// if (_brain != NULL) { delete _brain; }
	return ;
}

Dog::Dog(const Dog& to_copy) : Animal() {
	std::cout << "Dog copy constructor Called" << std::endl;
	if (this->_brain != NULL) { (*this->_brain = *to_copy._brain); }
	this->_type = to_copy.getType();
	return ;
}

Dog&		Dog::operator=(Dog const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs.getType();
		if (this->_brain != NULL) { *this->_brain = *rhs._brain; }
	}
	std::cout << "Dog equal operator overload Called" << std::endl;
	return (*this);
}

void		Dog::makeSound( void ) const {
	std::cout << "Woof ! Woof ! Woof !" << std::endl;
	return ;
}

void	Dog::set_idea( const std::string& new_idea ) const {
	_brain->set_idea(new_idea);
}

void	Dog::print_idea( int n ) const {
	_brain->print_idea(n);
}

void	Dog::print_idea_list( void ) const {
	_brain->print_idea_list();
}
