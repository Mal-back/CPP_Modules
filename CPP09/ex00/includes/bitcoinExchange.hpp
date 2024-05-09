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

	private :
		BitcoinExchange( const BitcoinExchange& to_copy);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		std::map<int*, double> _db;
		void	_parseDate(const char *c_line, int *date) const;
};

#endif
