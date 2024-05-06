/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:33:27 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/25 18:33:28 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ostream>
#ifndef BUREAUCRAT_HPP

#include <string>

# define BUREAUCRAT_HPP

class Bureaucrat {

	public :

		Bureaucrat( void );
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& to_copy);
		~Bureaucrat( void );

		Bureaucrat&		operator=(const Bureaucrat& rhs);

		std::string		getName( void ) const;
		int						getGrade( void ) const;
		void					incrementGrade( void );
		void					decrementGrade( void );
		class GradeTooLow : public std::exception {
			public :

				virtual const char* what() const throw();
		};
		class GradeTooHigh : public std::exception {
			public :

				virtual const char* what() const throw();
		};

	private :

		std::string		_name;
		int						_grade;
		void					_setGrade(int grade);
};

std::ostream&		operator<<( std::ostream& o, const Bureaucrat& rhs);

#endif // !BUREAUCRAT_HPP
