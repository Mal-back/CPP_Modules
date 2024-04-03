/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:41:37 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 16:41:38 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

	public :

		Zombie(void);
		~Zombie(void);

		void	announce(void) const;
		void	set_name(std::string name);

	private :

		std::string	name;

};

Zombie	*zombieHorde(int n, std::string name);

#endif
