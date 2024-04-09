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

# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
 
class FragTrap : public ClapTrap {

	public:

		FragTrap( void );
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& to_copy);
		~FragTrap( void );

		FragTrap&		operator=(FragTrap const& rhs);

		void				highFiveGuys( void ) const;
		void				attack(const std::string& target_name);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				printStat( void ) const;
} ; 

#endif
