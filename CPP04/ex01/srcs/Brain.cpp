/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:22:30 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/10 16:22:58 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) : _next_idea_to_fill(0) {
	std::cout << "Brain default constructor Called" << std::endl;
	return ;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor Called" << std::endl;
	return ;
}

Brain::Brain(const Brain& to_copy) {
	std::cout << "Brain copy constructor Called" << std::endl;
	*this = to_copy;
	return ;
}

Brain&		Brain::operator=(Brain const& rhs) {	
	if (this != &rhs)
	{
		for(int i = 0; i < rhs._get_next_idea_index(); ++i) {
			this->set_idea(rhs._get_idea(i));
		}
	}
	std::cout << "Brain equal operator overload Called" << std::endl;
	return (*this);
}

int	Brain::_get_next_idea_index( void ) const {
	return( this->_next_idea_to_fill);
}

void	Brain::_update_idea_index( void ) {
	this->_next_idea_to_fill += 1;
	return ;
}

void	Brain::set_idea(const std::string& idea) {
	int	index = _get_next_idea_index();
	if (index == 100) {
		std::cout << "This brain cannot contains more than 100 ideas ..." << std::endl;
	} else {
		this->_ideas[index] = idea;
		this->_update_idea_index();
	}
	return ;
}

const	std::string&	Brain::_get_idea(int index) const {
	return (this->_ideas[index]);	
}

void	Brain::print_idea(int n) const {
	if (n >= this->_get_next_idea_index()) {
		std::cout << "This idea doesn't exists inside this brain ..." << std::endl;
	} else {
		std::cout << _get_idea(n) << std::endl;
	}
	return ;
}

void	Brain::print_idea_list( void ) const {
	for (int i = 0; i < this->_get_next_idea_index(); ++i) {
		print_idea(i);
	}
	return ;
}
