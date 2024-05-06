/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:17:55 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 12:17:56 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target ) :
	AForm("ShrubberyCreationForm", 145, 137) {
		this->_target = target + "_shrubbery";
	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy):
AForm(to_copy.getName(), to_copy.getSignedRank(), to_copy.getExecRank()) {
	this->_target = to_copy.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	return ;
}

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	} 
	return (*this);
}

void		ShrubberyCreationForm::_printForm( void ) const {
	std::ofstream to_write;
	to_write.open(this->getTarget().c_str(), std::ofstream::trunc);
	if (to_write.fail()) {
		std::cerr << "Failed to open " << this->getTarget() << " because "
			<< strerror(errno) << std::endl;
	} to_write << SHRUB;
	to_write.close();
}

const std::string&		ShrubberyCreationForm::getTarget( void ) const {
	return (this->_target);
}
