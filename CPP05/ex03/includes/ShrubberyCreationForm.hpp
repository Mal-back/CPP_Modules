/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:48:51 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/26 11:48:52 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

# define SHRUBBERYCREATIONFORM_HPP

# define SHRUB "\n\
           {{ }{\n\
          {{}}}{{\n\
        {{}}{}}\n\
           }}}}{\n\
          {{}}}\n\
         }{{}{}}\n\
           {{}{}}\n\
         }}{{}}\n\
          {{}}{{\n\
           \\  /\n\
        .-''| |``-.\n\
       '-._/_o_\\_.-'\n\
        `._     _.'\n\
         | :F_P: |\n\
         `._    .'\n\
            `--'\n"

class ShrubberyCreationForm : public AForm {

	public :

		ShrubberyCreationForm( const std::string& target);
		ShrubberyCreationForm( const ShrubberyCreationForm& to_copy);
		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm&		operator=(ShrubberyCreationForm const& rhs);

		virtual const std::string&			getTarget( void ) const;

	private :

		std::string		_target;

		virtual void _printForm( void ) const;
} ;

#endif
