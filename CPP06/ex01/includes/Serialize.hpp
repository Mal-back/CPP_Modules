/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:34:53 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 18:34:54 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP

# define SERIALIZE_HPP

#include <Data.hpp>

typedef unsigned long uintptr_t;

class Serialize {

	public :

		Serialize( void );
		Serialize( const Serialize& to_copy);
		virtual ~Serialize( void ) = 0;

		Serialize& operator=(const Serialize& rhs);
		
		static uintptr_t serialize(t_data *ptr);
		static t_data	*deserialize(uintptr_t raw);
};

#endif
