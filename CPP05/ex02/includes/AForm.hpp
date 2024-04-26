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

#ifndef AFORM_HPP

# define AFORM_HPP

#include <ostream>
#include <string>
class Bureaucrat;

class AForm {

	public :

		AForm( void );
		AForm( const std::string& name, const int signRank, const int execRank );
		AForm( const AForm& to_copy);
		virtual ~AForm( void );

		AForm&		operator=(const AForm& rhs);

		int 														getSignedRank( void ) const;
		bool														getState( void ) const;
		void														beSigned(const Bureaucrat& signingOne);
		int 														getExecRank( void ) const;
		const std::string								getName( void ) const;
		void														execute(const Bureaucrat& executor) const;
		class GradeTooLow : public std::exception {
			public :

				virtual const char* what() const throw();
		};
		class FormNotSigned : public std::exception {
			public :

				virtual const char* what() const throw();
		};

	protected :

		virtual void		_printForm( void ) const = 0;

	private :

		const std::string	_name;
		bool							_isSigned;
		const int					_execRank;
		const int					_SignRank;


};

std::ostream&		operator<<(std::ostream &o, const AForm& rhs);

#endif
