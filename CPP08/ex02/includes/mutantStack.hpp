/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:16:21 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/07 19:16:22 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP

# define MUTANTSTACK_HPP

#include <stack>
template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container > {
	public :
		MutantStack() : MutantStack<T, Container>::stack() {};
		MutantStack(const MutantStack<T>& other) : MutantStack<T, Container>::stack(other) {};

		MutantStack&	operator=(const MutantStack<T, Container>& rhs) {
			if (this != &rhs) {
				this->MutantStack<T, Container>::stack::operator=(rhs);
			} return (*this);
		}

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;

		iterator 				begin( void ) {return this->c.begin(); };
		const iterator	begin( void ) const {return this->c.begin(); };

		iterator 				end( void ) {return this->c.end(); };
		const iterator	end( void ) const {return this->c.end(); };

		reverse_iterator 				rbegin( void ) {return this->c.rbegin(); };
		const reverse_iterator	rbegin( void ) const {return this->c.rbegin(); };

		reverse_iterator 				rend( void ) {return this->c.rend(); };
		const reverse_iterator	rend( void ) const {return this->c.rend(); };
};

#endif
