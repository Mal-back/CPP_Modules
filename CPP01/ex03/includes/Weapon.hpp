/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:35:18 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 19:35:19 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# include <string>

# define WEAPON_HPP

class Weapon {

	public :

		Weapon(std::string type);
		~Weapon( void );


		const	std::string getType(void) const;
		void							setType(std::string new_weapon);

	private :
		std::string type;

};

#endif
