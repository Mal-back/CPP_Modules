/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:28:38 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/25 19:28:39 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <new>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "RobotyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	std::cout << "Creating John with a grade of 42" << std::endl;
	Bureaucrat john("john", 42);
	std::cout << "Creating Lisa with a grade of 0" << std::endl;
	Bureaucrat lisa("lisa", 0);
	std::cout << "Creating Richie with a grade of 212" << std::endl;
	Bureaucrat richie("richie", 212);	
	std::cout << john << std::endl; 
	std::cout << lisa << std::endl; 
	std::cout << richie << std::endl; 
	std::cout << "Incrementing john until is grade is above 1" << std::endl;
	for (int i = 0; i < 45; ++i) {
		try {
			john.incrementGrade();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << john << std::endl;
	std::cout << "Decrementing john until is grade is below 1" << std::endl;
	for (int i = 0; i < 155; ++i) {
		try {
			john.decrementGrade();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << john << std::endl;

	// AForm	random;
	//
	// std::cout << "New Form info : " << random << std::endl;
	// std::cout << "John will try to sign the form" << std::endl;
	// john.signForm(random);
	// std::cout << "Form Info :" << std::endl << random << std::endl;
	// std::cout << "Lisa will help John" << std::endl;
	// lisa.signForm(random);
	// std::cout << "Form Info :" << std::endl << random << std::endl;

	ShrubberyCreationForm		shrub("lala");
	RobotomyRequestForm			robot("Intern");
	PresidentialPardonForm	pardon("mesrine");	

	std::cout << "Print all form states : " << std::endl;
	std::cout << shrub << std::endl << robot << std::endl << pardon << std::endl;
	std::cout << lisa << std::endl;
	std::cout << "Lisa will try to execute everything" << std::endl;
	lisa.executeForm(shrub);
	lisa.executeForm(robot);
	lisa.executeForm(pardon);
	std::cout << john << std::endl;
	std::cout << "John will try to sign everything" << std::endl;
	john.signForm(shrub);
	john.signForm(robot);
	john.signForm(pardon);
	std::cout << "Lisa will help John" << std::endl;
	lisa.signForm(shrub);
	lisa.signForm(robot);
	lisa.signForm(pardon);
	std::cout << "Print all form states : " << std::endl;
	std::cout << shrub << std::endl << robot << std::endl << pardon << std::endl;
	std::cout << "Incrementing john grade to 130" << std::endl;
	for (int i = 0; i < 20; ++i) {
		john.incrementGrade();
	}
	std::cout << john << std::endl;
	std::cout << "John will try to execute everything" << std::endl;
	john.executeForm(shrub);
	john.executeForm(robot);
	john.executeForm(pardon);
	std::cout << "Lisa will try to execute everything" << std::endl;
	lisa.executeForm(shrub);
	lisa.executeForm(robot);
	lisa.executeForm(pardon);

	Intern random;
	AForm* form1;
	AForm* form2;
	AForm* form3;

	std::cout << "Intern is here" << std::endl;
	try {
		form1 = random.makeForm("ShrubberyCreationForm", "lalala");
	} catch (std::bad_alloc& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	try {
		form2 = random.makeForm("PresidentialPardonForm", "lalala");
	} catch (std::bad_alloc& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	try {
		form3 = random.makeForm("Failed", "lalala");
	} catch (std::bad_alloc& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	try {
		form3 = random.makeForm("PresidentialPardonForm", "lalala");
	} catch (std::bad_alloc& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	lisa.signForm(*form1);
	lisa.signForm(*form2);
	lisa.signForm(*form3);
	lisa.executeForm(*form1);
	lisa.executeForm(*form2);
	lisa.executeForm(*form3);
	delete form1;
	delete form2;
	delete form3;
}
