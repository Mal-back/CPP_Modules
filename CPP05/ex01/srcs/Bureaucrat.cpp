/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:53:29 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/25 18:53:30 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat( void ) : _name("Anonymous"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	try {
		_setGrade(grade);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat&	to_copy): _name(to_copy.getName()) {
	*this = to_copy;
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	return ;
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

void		Bureaucrat::decrementGrade() {
	if (this->getGrade() == 150) {
		throw GradeTooLow();
	} else {
		this->_grade += 1;
	}
	return ;
}

void		Bureaucrat::incrementGrade() {
	if (this->getGrade() == 1) {
		throw GradeTooHigh();
	} else {
		this->_grade -= 1;
	}
	return ;
}

void		Bureaucrat::_setGrade( int grade ) {
	if (grade < 1) {
		_grade = 1;
		throw GradeTooHigh();
	} else if (grade > 150) {
		_grade = 150;
		throw GradeTooLow();
	} else {
		_grade = grade;	
	}
}

std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

int		Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

const char*		Bureaucrat::GradeTooLow::what() const throw() {
	return ("Grade too low. Grade is set to 150.");
}

const char*		Bureaucrat::GradeTooHigh::what() const throw() {
	return ("Grade too high. Grade is set to 1.");
}

void	Bureaucrat::signForm(Form& to_sign) {
	try {
		to_sign.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << to_sign.getName() 
			<< " because" << e.what() << std::endl;
		return ;
	} std::cout << this->getName() << " successefuly sign " << to_sign.getName() << std::endl;
}

std::ostream&		operator<<(std::ostream& o, const Bureaucrat& rhs) {
	std::cout << rhs.getName() << " grade's is : " << rhs.getGrade() << std::endl;
	return (o);
}
