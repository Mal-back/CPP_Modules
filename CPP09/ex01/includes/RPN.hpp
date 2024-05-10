/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:03:25 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/10 16:03:26 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

# define RPN_HPP

#include <stack>
#include <string>

class RPN {
	public : 
		
		RPN(const std::string& input);
		~RPN( void );

		class wrongInput : public std::exception {
			const char*	what() const throw();
		};

		int		evaluate( void );

	private :

		RPN( void );
		RPN(const RPN& to_copy);
		RPN&	operator=(const RPN& rhs);

		inline int	_isOp( char c ) const;
		inline void	_doOp(char c);

		std::stack<int>	_container;
		std::string				_input;
};

#endif
