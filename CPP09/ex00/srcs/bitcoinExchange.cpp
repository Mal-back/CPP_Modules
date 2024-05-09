/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinExhange.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:45:24 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/09 19:45:24 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bitcoinExchange.hpp>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange( void) {
	std::ifstream db;

	db.open("data.csv");
	if (db.fail()) {
		throw databaseParsingError();
	}
	std::string	line;
	const char	*c_line;
	int 				*date;
	char				*endptr;
	double			amount;

	std::getline(db, line);
	while(std::getline(db, line)) {
		date = new int[3];
		if (line.size() < 12) {
			throw databaseParsingError();
		} if (line[10] != ',') {
			throw databaseParsingError();
		}
		c_line = line.c_str();
		try {
			this->_parseDate(c_line, date);
		} catch (std::exception& e) {
			throw databaseParsingError();
		}
		amount = std::strtod(c_line + 11, &endptr);
		if (*endptr != '\0') {
			throw databaseParsingError();
		}
		this->_db.insert(std::pair<int*, double>(date, amount));
	}
}

BitcoinExchange::~BitcoinExchange( void ) {
	for (std::map<int *, double>::iterator it = this->_db.begin(); it != this->_db.end(); ++it) {
		delete [] it->first;
	}
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& to_copy ) {
	(void)to_copy;
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	(void)rhs;
	return (*this);
}

void	BitcoinExchange::_parseDate( const char	*c_line, int *date) const {
	char				*endptr;
	date[YEAR] = std::strtod(c_line, &endptr);
	if (*endptr != '-' || date[YEAR] < 2009 || date[YEAR] > 2022) {
		throw dateParsingError();
	}
	date[MONTH] = std::strtod(c_line + 5, &endptr);
	if (*endptr != '-' || date[MONTH] < 1 || date[MONTH] > 12) {
		throw dateParsingError();
	}
	date[DAY] = std::strtod(c_line + 8, &endptr);
	if (*endptr != ',' || date[DAY] < 0) {
		throw dateParsingError();
	}
	if (date[MONTH] == 02) {
		if (date[YEAR] % 4 == 0 && date[DAY] > 29) {
			throw dateParsingError();
		} else if (date[DAY] > 28) {
			throw dateParsingError();
		}
	}
	else if ((date[MONTH] <= 7 && date[MONTH] % 2 == 1)
			|| (date[MONTH] >= 8 && date[MONTH] % 2 == 0)) {
		if (date[DAY] > 31) {
			throw dateParsingError();
		} else if (date[MONTH] > 30) {
			throw dateParsingError();
		}
	}
	return ;
}

const char*		BitcoinExchange::databaseParsingError::what() const throw() {
	return ("An error occured while parsing data.csv");
}

const char*		BitcoinExchange::dateParsingError::what() const throw() {
	return ("Error : bad input");
}
