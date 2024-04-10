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

#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>
 
class ScavTrap : virtual public ClapTrap {

	public:

		ScavTrap( void );
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& to_copy);
		~ScavTrap( void );

		ScavTrap&		operator=(ScavTrap const& rhs);

		void				guardGate( void );
		void				attack(const std::string& target_name);
		void				printStat( void ) const;
} ; 

#endif
