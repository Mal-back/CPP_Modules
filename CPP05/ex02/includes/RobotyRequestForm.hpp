/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotyRequestForm.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:54 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 11:59:09 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

# define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm {

	public :

		RobotomyRequestForm( const std::string& target);
		RobotomyRequestForm( const RobotomyRequestForm& to_copy);
		~RobotomyRequestForm( void );

		RobotomyRequestForm&		operator=(RobotomyRequestForm const& rhs);

		virtual const std::string&			getTarget( void ) const;

	private :

		std::string		_target;

		virtual void _printForm( void ) const;
} ;

#endif
