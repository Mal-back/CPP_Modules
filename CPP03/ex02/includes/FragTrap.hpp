/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:24:03 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 19:24:04 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

# define FRAGTRAP_HPP
 
class FragTrap : public ClapTrap {

	public:

		FragTrap( void );
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& to_copy);
		~FragTrap( void );

		FragTrap&		operator=(FragTrap const& rhs);

		void				highFiveGuys( void ) const;
		void				printStat( void ) const;
} ; 

#endif
