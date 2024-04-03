/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:44:40 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 19:44:52 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# include <string>
# include "Weapon.hpp"

# define HUMANA_HPP

class HumanA {

	public :

		HumanA(std::string name, Weapon& weapon);
		~HumanA( void );
		
		void	attack( void );



	private :

		std::string	name;
		Weapon&			Current_Weapon;

};

#endif
