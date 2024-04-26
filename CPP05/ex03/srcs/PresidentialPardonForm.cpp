/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialParodnForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:29:47 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 15:29:47 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target ) :
	AForm("PresidentialPardonForm", 25, 5) {
		this->_target = target;
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy):
AForm(to_copy.getName(), to_copy.getSignedRank(), to_copy.getExecRank()) {
	this->_target = to_copy.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	return ;
}

PresidentialPardonForm&		PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	} 
	return (*this);
}

void		PresidentialPardonForm::_printForm( void ) const {
	std::cout << this->getTarget() << " was parodnned by Zaphod Beeblebrox" << std::endl;
}

const std::string&		PresidentialPardonForm::getTarget( void ) const {
	return (this->_target);
}
