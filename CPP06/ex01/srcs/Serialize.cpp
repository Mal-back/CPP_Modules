/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:45:14 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 18:45:14 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <Serialize.hpp>

Serialize::Serialize( void ) {
	return ;
}

Serialize::Serialize( const Serialize& to_copy ) {
	(void)to_copy;
	return ;
}

Serialize&	Serialize::operator=(const Serialize& rhs) {
	(void)rhs;
	return (*this);
}

uintptr_t	Serialize::serialize(t_data *ptr) {
	return(reinterpret_cast<uintptr_t>(ptr));
}

t_data *Serialize::deserialize(uintptr_t raw) {
	return (reinterpret_cast<t_data *>(raw));
}
