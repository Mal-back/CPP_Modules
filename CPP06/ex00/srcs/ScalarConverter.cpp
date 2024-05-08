/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:41:04 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 16:41:07 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <float.h>
#include <string>

ScalarConverter::ScalarConverter( void ) {
	return ;
}

ScalarConverter::ScalarConverter( const ScalarConverter& to_copy ) {
	(void)to_copy;
	return ;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return (*this);
}

void	ScalarConverter::convert(const std::string &litteral) {
		size_t 	i = 0;
		char	letter;
		char 	*endptr;
		double number;

		if (litteral.size() - i == 1 && std::isprint(*litteral) != 0
				&& std::isdigit(litteral[i]) == 0) {
			letter = litteral[i];
			std::cout << "Char : '" << litteral[i] << "'" << std::endl;
			std::cout << "Int : " << static_cast<int>(letter) << std::endl;
			std::cout << "Float : " << static_cast<float>(letter) << ".0f" << std::endl;
			std::cout << "Double : " << static_cast<double>(letter) << ".0" << std::endl;
			return ;
		} else if (litteral.compare(i, litteral.size() - i, "inf") == 0
				|| litteral.compare(i, litteral.size() - i, "-inf") == 0)  {
			std::cout << "Char : Impossible" << std::endl;
			std::cout << "Int : Impossible" << std::endl;
			std::cout << "Float : nanf" << std::endl;
			std::cout << "Double : " << &litteral[i] << std::endl;
			return ;
		} else if (litteral.compare(i, litteral.size() - i, "inff") == 0
				|| litteral.compare(i, litteral.size() - i, "-inff") == 0)  {
			std::cout << "Char : Impossible" << std::endl;
			std::cout << "Int : Impossible" << std::endl;
			std::cout << "Float : " << &litteral[i] << std::endl;
			std::cout << "Double : nan" << std::endl;
			return ;
		}
		number = std::strtod(litteral.c_str(), &endptr);
		if (*endptr != '\0') {
			if (*endptr == 'f' && *(endptr + 1) == '\0') {
				number = std::strtof(litteral.c_str(), &endptr);
			} else {
				std::cout << "Char : Impossible" << std::endl;
				std::cout << "Int : Impossible" << std::endl;
				std::cout << "Float : nanf" << std::endl;
				std::cout << "Double : nan" << std::endl;
				return ;
			}
		}
		if (errno == ERANGE) {
			std::cout << "Char : Impossible" << std::endl;
			std::cout << "Int : Impossible" << std::endl;
		}
		for 
			std::cout << "Float : nanf" << std::endl;
			std::cout << "Double : nan" << std::endl;
			return ;
		}
		if (number >= 32 && number < 127) {
			std::cout << "Char : '" << static_cast<char>(number) << "'" << std::endl;
		} else {
			std::cout << "Char : Non Displayable" << std::endl;
		}
		if (number > INT_MAX || number < INT_MIN) {
		std::cout << "Int : Impossible" << std::endl;
		} else {
			std::cout << "Int : " << static_cast<int>(number) << std::endl;
		}
		if (number > FLT_MAX) {
			std::cout << "Float : inff" << std::endl;
		} else if (number < FLT_MIN)
			std::cout << "Float : -inff" << std::endl;
		else {
			std::cout << "Float : ";
			if (number == static_cast<int>(number)) {
				std::cout << std::fixed << std::setprecision(1) << number; 
			} else {
				std::cout << static_cast<float>(number);
			} std::cout << "f" << std::endl;
		}
		std::cout << "Double : ";
		if (number == static_cast<int>(number)) {
			std::cout << std::fixed << std::setprecision(1) << number <<std::endl; 
		} else {
			std::cout << number << std::endl;
		}

		return ;
}
