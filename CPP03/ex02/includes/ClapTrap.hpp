/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:31:33 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 16:31:33 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

#include <string>
#include <iostream>

# define CLAPTRAP_HPP

class ClapTrap {

	public :

		ClapTrap( void );
		ClapTrap( std::string name);
		ClapTrap( ClapTrap const& to_copy);
		~ClapTrap( void );

		ClapTrap&		operator=(ClapTrap const& rhs);

		void				attack(const std::string& target_name);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				printStat( void ) const;

	protected :

		std::string		_name;
		int						_attackDamage;
		int						_hitPoints;
		int						_energyPoint;
} ;

#endif
