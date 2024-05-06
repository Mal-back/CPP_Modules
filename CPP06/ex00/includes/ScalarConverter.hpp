/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:20:53 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 15:20:54 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {

	public :

		ScalarConverter( void );
		ScalarConverter(const ScalarConverter& to_copy);
		virtual ~ScalarConverter( void ) = 0;

		ScalarConverter&	operator=(const ScalarConverter& rhs);
		static void	convert(const std::string& litteral);
};

#endif
