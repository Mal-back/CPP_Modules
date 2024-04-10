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
	this->_type = to_copy._type;
	return ;
}

Animal&		Animal::operator=(Animal const& rhs) {	
	if (this != &rhs) {
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	std::cout << "Animal equal operator overload Called" << std::endl;
	return (*this);
}

void		Animal::makeSound( void ) const {
	return ;
}

bool	Animal::getBrainIntegrity( void ) const {
	if (this->_brain == NULL) {
		return (false);
	} else {
		return (true);
	}
}

void	Animal::set_idea( const std::string& new_idea ) const {
	_brain->set_idea(new_idea);
}

void	Animal::print_idea( int n ) const {
	_brain->print_idea(n);
}

void	Animal::print_idea_list( void ) const {
	_brain->print_idea_list();
}
