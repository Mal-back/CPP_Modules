/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:50:38 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/28 16:50:57 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP

# define TEMPLATES_HPP

template<typename T>
void	swap(T& a, T& b) {
	const T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& min(const T& a, const T&b) {
	return (a < b ? a: b);
}

template<typename T>
const T& max(const T& a, const T&b) {
	return (a > b ? a: b);
}

#endif
