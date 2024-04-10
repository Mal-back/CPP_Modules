/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:56:03 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 20:01:36 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {

	public :

		DiamondTrap( void );
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& to_copy);
		~DiamondTrap( void );

		DiamondTrap&		operator=(DiamondTrap const& rhs);

		using 					ScavTrap::attack;
		void						printStat( void ) const;
		void						whoAmI( void ) const;

	private :

		std::string		_name;

};

#endif
