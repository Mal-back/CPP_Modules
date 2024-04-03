/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:59:07 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 19:59:08 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# include <string>
# include "Weapon.hpp"

# define HUMANB_HPP

class HumanB {

	public :

		HumanB(std::string name);
		~HumanB( void );
		
		void	attack( void );
		void	setWeapon(Weapon& new_weapon);



	private :

		Weapon			*Current_Weapon;
		std::string	name;

};

#endif
