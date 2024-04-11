/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:05:58 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:06:16 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {

	public :

		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& to_copy );
		virtual ~WrongAnimal( void );

		WrongAnimal&			operator=(const WrongAnimal& rhs);

		virtual void				makeSound( void ) const;	
		const std::string&	getType( void ) const;

	protected :

		std::string					_type;
};

#endif
