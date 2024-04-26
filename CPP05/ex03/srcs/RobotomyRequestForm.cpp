/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:07:27 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 15:07:28 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) :
	AForm("RobotomyRequestForm", 72, 45) {
		this->_target = target;
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy):
AForm(to_copy.getName(), to_copy.getSignedRank(), to_copy.getExecRank()) {
	this->_target = to_copy.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	return ;
}

RobotomyRequestForm&		RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	} 
	return (*this);
}

void		RobotomyRequestForm::_printForm( void ) const {
	std::cout << "* some drilling noise" << std::endl << this->getTarget();
	srand((unsigned int)time(NULL));
	if (rand() > RAND_MAX / 2) {
		std::cout << " was successefully robotomized" << std::endl;
	} else {
		std::cout << " robotomization fail" << std::endl;
	} return ;
}

const std::string&		RobotomyRequestForm::getTarget( void ) const {
	return (this->_target);
}
