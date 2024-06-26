/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:22:15 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/28 17:22:15 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP

#include <iostream>

template < typename T, typename U >
void	iter(T *array_begin, size_t length, void (*func)(U&)) {
	for (size_t i = 0; i < length; ++i) {
		func(array_begin[i]);
	}	
	return ;
}

#endif
