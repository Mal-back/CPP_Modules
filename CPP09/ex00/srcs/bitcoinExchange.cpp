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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange( void ) {
	std::ifstream db;
	std::map<std::string, double> nmap;

	db.open("data.csv");
	if (db.fail()) {
		throw databaseParsingError();
	}
	std::string	line;
	const char	*c_line;
	char				*endptr;
	std::string date;
	double			amount;

	std::getline(db, line);
	if (line.compare("date,exchange_rate") != 0) {
			throw databaseParsingError();
	}
	while(std::getline(db, line)) {
		if (line.size() < 12) {
			throw databaseParsingError();
		} if (line[10] != ',') {
			throw databaseParsingError();
		}
		c_line = line.c_str();
		try {
			date = this->_parseDate(c_line);
		} catch (std::exception& e) {
			throw databaseParsingError();
		}
		amount = std::strtod(c_line + 11, &endptr);
		if (*endptr != '\0' || amount < 0) {
			throw databaseParsingError();
		}
		this->_db.insert(std::pair<std::string, double>(date, amount));
	}
}

BitcoinExchange::~BitcoinExchange( void ) {
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

void	BitcoinExchange::exchange(std::ifstream& input) const {
	std::pair<std::string, double>	entry;
	std::string											line;
	char														*endptr;
	
	std::getline(input, line);
	if (line.compare("date | value") != 0) {
		std::cout << "Error : Wrong header" << std::endl;
	}
	while(std::getline(input, line)) {
		if (line.size() < 13 || line.compare(10, 3, " | ")) {
			std::cout << "Error : Wrong input format" << std::endl;
		} else {
			try {
				entry.first = _parseDate(line.c_str());
			} catch ( std::exception& e) {
				std::cout << e.what() << " => " << line.erase(10) << std::endl;
				continue;
			}
				if (entry.first < this->_db.begin()->first) {
				std::cout << "Error : Date is before first database entry =>" << line.erase(10) << std::endl;
			} else if (entry.first > "2024-05-10") {
				std::cout << "Error : Date is in the future =>" << line.erase(10) << std::endl;
			} else {
				entry.second = std::strtod(line.c_str() + 12, &endptr);
				if (*endptr != '\0') {
					std::cout << "Error : Wrong input format" << std::endl;
				} else if (entry.second > 1000) {
					std::cout << "Error : too large a number" << std::endl;
				} else if (entry.second < 0) {
					std::cout << "Error : not a positive number" << std::endl;
				} else {
					this->_findExchangeRate(entry);
				}
			}
		}
	}
	return ;
}

std::string BitcoinExchange::_parseDate( const char	*c_line) const {
	char				*endptr;
	int					date[3];
	date[YEAR] = std::strtod(c_line, &endptr);
	if (*endptr != '-' || date[YEAR] < 2000 || date[YEAR] > 2024) {
		throw dateParsingError();
	}
	date[MONTH] = std::strtod(c_line + 5, &endptr);
	if (*endptr != '-' || date[MONTH] < 1 || date[MONTH] > 12) {
		throw dateParsingError();
	}
	date[DAY] = std::strtod(c_line + 8, &endptr);
	if (date[DAY] < 0) {
		throw dateParsingError();
	}
	if (date[MONTH] == 02) {
		if (date[YEAR] % 4 == 0) {
			if (date[DAY] > 29) {
				throw dateParsingError();
		}
		} else if (date[DAY] > 28) {
			throw dateParsingError();
		}
	}
	else if ((date[MONTH] <= 7 && date[MONTH] % 2 == 1)
			|| (date[MONTH] >= 8 && date[MONTH] % 2 == 0)) {
		if (date[DAY] > 31) {
			throw dateParsingError();
		}
	}
	else if (date[DAY] > 30) {
			throw dateParsingError();
		}
	std::string ret(c_line);
	return (ret.erase(10));
}

void	BitcoinExchange::_findExchangeRate(const std::pair<std::string, double>& entry) const{
	std::map<std::string, double>::const_iterator	it = this->_db.find(entry.first);

	if (it != this->_db.end()) {
		std::cout << entry.first << " => "<< it->second * entry.second << std::endl;
	} else {
		std::map<std::string, double>::const_iterator	prev = this->_db.begin();
		for (it = this->_db.begin()++; it != this->_db.end(); ++it) {
			if (it->first > entry.first) {
				std::cout << entry.first << " => "<< prev->second * entry.second << std::endl;
				break ;
			}	
			prev = it;
		}
	}
}

const char*		BitcoinExchange::databaseParsingError::what() const throw() {
	return ("An error occured while parsing data.csv");
}

const char*		BitcoinExchange::dateParsingError::what() const throw() {
	return ("Error : bad input");
}
