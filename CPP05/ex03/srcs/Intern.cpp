/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:15:06 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 16:15:06 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotyRequestForm.hpp"
#include <iostream>

const std::string Intern::_knownForm[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", 
			"PresidentialPardonForm"};

Intern::Intern( void ) {
	return ;
}

Intern::Intern(const Intern& to_copy) {
	(void)to_copy;
	return ;
}

Intern::~Intern( void ) {
	return ;
}

Intern&		Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return (*this);
}

AForm*		Intern::makeForm(const std::string& form, const std::string& target) const {
	int i;
	AForm *created = NULL;
	for(i = 0; form.compare(this->_knownForm[i]) != 0 && i < 3; ++i) {}
	switch (i) {
		case 0:
			created = new ShrubberyCreationForm(target);
			break;
		case 1:
			created = new RobotomyRequestForm(target);
			break;
		case 2:
			created = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Intern doesn't know the form : " << form << std::endl;
			return (NULL);
			break;
	}
	std::cout << "Intern successefully created " << form << std::endl;
	return (created);
}
