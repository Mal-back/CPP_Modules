/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:01:24 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 12:01:25 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

# define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public AForm {

	public :

		PresidentialPardonForm( const std::string& target);
		PresidentialPardonForm( const PresidentialPardonForm& to_copy);
		~PresidentialPardonForm( void );

		PresidentialPardonForm&		operator=(PresidentialPardonForm const& rhs);

		virtual const std::string&			getTarget( void ) const;

	private :

		std::string		_target;

		virtual void _printForm( void ) const;
} ;

#endif
