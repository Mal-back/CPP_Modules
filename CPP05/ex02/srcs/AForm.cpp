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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm( void ): _name("Random AForm"), _isSigned(false),
	_execRank(20), _SignRank(5) {
	return ;
}

AForm::AForm( const std::string& name, const int signRank, const int execRank) :
	_name(name), _isSigned(false), _execRank(execRank), _SignRank(signRank) {
		return ;
	}

AForm::AForm(const AForm& to_copy): _name(to_copy.getName()),
_isSigned(to_copy.getState()) ,_execRank(to_copy.getExecRank()),
	_SignRank(to_copy.getSignedRank()) {
	return ;
}

AForm::~AForm( void ) {
	return ;
}

AForm&		AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs.getState();
	}	
	return (*this);
}

std::ostream&		operator<<(std::ostream &o, const AForm& rhs) {
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

int	AForm::getSignedRank( void ) const {
	return (this->_SignRank);
}

int	AForm::getExecRank( void ) const {
	return (this->_execRank);
}

bool	AForm::getState( void ) const {
	return(this->_isSigned);
}

const std::string AForm::getName( void ) const {
	return (this->_name);
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (this->getState() == false) {
		throw FormNotSigned();
	} else if (this->_execRank < executor.getGrade()) {
		throw GradeTooLow();
	} else {
		this->_printForm();
	}
}

const char*		AForm::GradeTooLow::what() const throw() {
	return (" Grade too low, bureaucrat couldn't sign the form");
}

const char*		AForm::FormNotSigned::what() const throw() {
	return (" Form is not signed, couldn't be executed");
}

void	AForm::beSigned(const Bureaucrat& signing_one) {
	if (this->getSignedRank() < signing_one.getGrade()) {
		throw GradeTooLow();
	} else {
		this->_isSigned = true;
	}
	return ;
}
