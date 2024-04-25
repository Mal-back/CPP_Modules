/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:17:04 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/25 21:17:06 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <memory_resource>

Form::Form( void ): _name("Random Form"), _isSigned(false),
	_execRank(20), _SignRank(5) {
	return ;
}

Form::Form(const Form& to_copy): _name(to_copy.getName()),
_isSigned(to_copy.getState()) ,_execRank(to_copy.getExecRank()),
	_SignRank(to_copy.getSignedRank()) {
	return ;
}

Form::~Form( void ) {
	return ;
}

Form&		Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getState();
	}	
	return (*this);
}

std::ostream&		operator<<(std::ostream &o, const Form& rhs) {
	std::cout << "Form Name : " << rhs.getName() << std::endl;
	std::cout << "Form State : ";
	if (rhs.getState() == false) {
		std::cout << "false";
	} else {
		std::cout << "true";
	} std::cout << std::endl;
	std::cout << "Form SignRank : " << rhs.getSignedRank() << std::endl;
	std::cout << "Form ExecRank : " << rhs.getExecRank();

	return (o);
}

int	Form::getSignedRank( void ) const {
	return (this->_SignRank);
}

int	Form::getExecRank( void ) const {
	return (this->_execRank);
}

bool	Form::getState( void ) const {
	return(this->_isSigned);
}

const std::string Form::getName( void ) const {
	return (this->_name);
}

const char*		Form::GradeTooLow::what() const throw() {
	return (" Grade too low, bureaucrat couldn't sign the form");
}

void	Form::beSigned(const Bureaucrat& signing_one) {
	if (this->getSignedRank() < signing_one.getGrade()) {
		throw GradeTooLow();
	} else {
		this->_isSigned = true;
	}
	return ;
}
