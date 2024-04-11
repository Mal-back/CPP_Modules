/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:21 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:07:22 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public :

		WrongCat( void );
		WrongCat( const WrongCat& to_copy );
		virtual ~WrongCat( void );

		WrongCat&			operator=(const WrongCat& rhs);

		virtual void				makeSound( void ) const;	
};

#endif
