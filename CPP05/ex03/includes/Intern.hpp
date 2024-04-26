/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:08:52 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 16:08:53 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP

#include "AForm.hpp"
#include <string>

# define INTERN_HPP

class Intern {

	public:

		Intern( void );
		Intern(const Intern& to_copy);
		~Intern( void );

		Intern&		operator=(const Intern& rhs);

		AForm	*makeForm(const std::string& form, const std::string& target) const;
		class UnkmownForm : public std::exception {
			public :

				virtual const char* what() const throw();
		};
	
	private :

		const static std::string	_knownForm[3];
};

#endif
