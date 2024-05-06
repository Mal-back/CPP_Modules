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
#include <ostream>
#include "Bureaucrat.hpp"

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
}
