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

# include "ClapTrap.hpp"
# include <string>
# include <iostream>
 
class FragTrap : virtual public ClapTrap {

	public:

		FragTrap( void );
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& to_copy);
		~FragTrap( void );

		FragTrap&		operator=(FragTrap const& rhs);

		void				highFiveGuys( void ) const;
		void				printStat( void ) const;
		int		getBaseHitPoints( void ) const;
		int		getBaseAttackDamage( void ) const;

	private :

		const int					_baseHitPoints;	
		const int					_baseAttackDamage;	
} ; 

#endif
