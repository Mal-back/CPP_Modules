/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:22:39 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/09 19:22:40 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <map>
#ifndef BITCOINEXCHANGE_HPP

#include <string>

# define BITCOINEXCHANGE_HPP

typedef enum e_date {
	YEAR,
	MONTH,
	DAY
}						t_date;

class BitcoinExchange {

	public :

		BitcoinExchange( void );
		~BitcoinExchange( void );

		class databaseParsingError : public std::exception {
			public :
				const char* what() const throw();
		};
		class dateParsingError : public std::exception {
			public :
				const char* what() const throw();
		};

		void	exchange(std::ifstream& input) const;

	private :
		BitcoinExchange( const BitcoinExchange& to_copy);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		std::map<std::string, double> _db;

		std::string	_parseDate(const char *c_line) const;
		void				_findExchangeRate(const std::pair<std::string, double>& entry) const;
};

#endif
