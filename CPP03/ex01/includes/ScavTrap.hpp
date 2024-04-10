/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:26:35 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 18:26:36 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include <iostream>

# define CLAPTRAP_HPP

 
class ScavTrap : public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& to_copy);
		~ScavTrap( void );

		ScavTrap&		operator=(ScavTrap const& rhs);

		void				guardGate( void ) const;
		void				attack(const std::string& target_name);
		void				printStat( void ) const;
} ; 

#endif
