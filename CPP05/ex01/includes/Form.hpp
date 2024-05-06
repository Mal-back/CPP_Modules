/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:04:46 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/25 21:05:17 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <ostream>
#include <string>
class Bureaucrat;

class Form {

	public :

		Form( void );
		Form( const Form& to_copy);
		~Form( void );

		Form&		operator=(const Form& rhs);

		int 							getSignedRank( void ) const;
		bool							getState( void ) const;
		void							beSigned(const Bureaucrat& signingOne);
		int 							getExecRank( void ) const;
		const std::string	getName( void ) const;
		class GradeTooLow : public std::exception {
			public :

				virtual const char* what() const throw();
		};

	private :

		const std::string	_name;
		bool							_isSigned;
		const int					_execRank;
		const int					_SignRank;

};

std::ostream&		operator<<(std::ostream &o, const Form& rhs);

#endif
