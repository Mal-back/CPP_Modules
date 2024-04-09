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

# define CLAPTRAP_HPP

#include "ClapTrap.hpp"
 
class ScavTrap : public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& to_copy);
		~ScavTrap( void );

		ScavTrap&		operator=(ScavTrap const& rhs);

		void				guardGate( void ) const;
		void				attack(const std::string& target_name);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				printStat( void ) const;
} ; 

#endif
