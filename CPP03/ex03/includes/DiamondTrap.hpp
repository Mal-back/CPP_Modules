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

class DiamondTrap : public FragTrap, public ScavTrap {

	public :

		DiamondTrap( void );
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& to_copy);
		~DiamondTrap( void );

		DiamondTrap&		operator=(DiamondTrap const& rhs);

		void						highFiveGuys( void ) const;
		void						guardGate( void );
		void						attack(const std::string& target_name);
		void						takeDamage(unsigned int amount);
		void						beRepaired(unsigned int amount);
		void						printStat( void ) const;
		void						whoAmI( void ) const;

	private :

		std::string		_name;

};

#endif
