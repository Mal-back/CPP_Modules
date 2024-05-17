/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:47:49 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/06 15:47:49 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <algorithm>
#include <exception>
#include <iostream>

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

class noMatchFound : public std::exception {
	public :
		const char* what() const throw() {
			return ("No match found in the current container");
		}
};

template < typename T >
typename T::iterator easyFind(T& to_search, int to_find) {
	typename T::iterator match = std::find(to_search.begin(), to_search.end(), to_find);

	if (match != to_search.end()) {
		std::cout << "Occurence found : " << *match << std::endl;
		return (match);
	} else {
		throw noMatchFound();
	}
	return match;
}

#endif
