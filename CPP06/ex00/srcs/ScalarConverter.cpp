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
#include <cstdlib>
#include <iostream>
#include <stdexcept>
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
		int		number;
		char	letter;
		float		float_num;
		double dec_number;

		while(litteral[i] == ' ') {++i;}
		if (litteral.size() - i == 1 && std::isprint(litteral[i]) != 0
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
		} if (litteral[i] == '-' || litteral[i] == '+') {++i;}
		while (std::isdigit(litteral[i]) != 0) {++i;}
		if (litteral[i] == '\0') {
			try {
				number = std::atoi(litteral.c_str());
				std::cout << "Char : ";
				if (number >= 32 && number <= 127) {
					std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
				} else {
					std::cout << "Impossible" << std::endl;
				}
				std::cout << "Int : " << number << std::endl;
				std::cout << "Float : " << static_cast<float>(number) << ".0f" << std::endl;
				std::cout << "Double :" << static_cast<double>(number) << ".0" << std::endl;
				return ;
			} catch (std::out_of_range& e) {
				std::cout << "Error : Overflow detected" << std::endl;
				std::cout << "Char : Impossible" << std::endl;
				std::cout << "Int : Impossible" << std::endl;
				std::cout << "Float : nanf" << std::endl;
				std::cout << "Double : nan" << std::endl;
				return ;
			}
		} else if (litteral[i] == '.') {++i;}
		while (std::isdigit(litteral[i]) != 0) {++i;}
		if (litteral[i] == '\0') {
			try {
				dec_number = std::atof(litteral.c_str());
				if (static_cast<long>(dec_number) > 2147483647 || static_cast<long>(dec_number) < -2147483648) {
					std::cout << "Char : Impossible" << std::endl << "Int : Impossible" << std::endl;
				} else {
					std::cout << "Char : ";
					if (static_cast<int>(dec_number) >= 32 && static_cast<int>(dec_number) <= 127) {
						std::cout << "'" << static_cast<char>(dec_number) << "'" << std::endl;
					} else {
						std::cout << "Impossible" << std::endl;
					}
					std::cout << "Int :" << static_cast<int>(dec_number) << std::endl;
				}
				std::cout << "Float : " << static_cast<float>(dec_number) << "f" << std::endl;
				std::cout << "Double :" << dec_number << std::endl;
				return ;
			} catch (std::out_of_range& e) {
				std::cout << "Error : Overflow detected" << std::endl;
				std::cout << "Char : Impossible" << std::endl;
				std::cout << "Int : Impossible" << std::endl;
				std::cout << "Float : nanf" << std::endl;
				std::cout << "Double : nan" << std::endl;
				return ;
			}
		} else if (litteral[i] == 'f' && litteral[i + 1] == '\0') {
			try {
				float_num = std::atof(litteral.c_str());
				if (static_cast<long>(float_num) > 2147483647 || static_cast<long>(float_num) < -2147483648) {
					std::cout << "Char : Impossible" << std::endl << "Int : Impossible" << std::endl;
				} else {
					std::cout << "Char : ";
					if (static_cast<int>(float_num) >= 32 && static_cast<int>(float_num) <= 127) {
						std::cout << "'" << static_cast<char>(float_num) << "'" << std::endl;
					} else {
						std::cout << "Impossible" << std::endl;
					}
					std::cout << "Int : " << static_cast<int>(float_num) << std::endl;
				}
				std::cout << "Float : " << float_num << "f" << std::endl;
				std::cout << "Double : " << static_cast<double>(float_num) << std::endl;
				return ;
			} catch (std::out_of_range& e) {
				std::cout << "Error : Overflow detected" << std::endl;
				std::cout << "Char : Impossible" << std::endl;
				std::cout << "Int : Impossible" << std::endl;
				std::cout << "Float : nanf" << std::endl;
				std::cout << "Double : nan" << std::endl;
				return ;
			}
		} else {
			std::cout << "Char : Impossible" << std::endl;
			std::cout << "Int : Impossible" << std::endl;
			std::cout << "Float : nanf" << std::endl;
			std::cout << "Double : nan" << std::endl;
		}
		return ;
}
