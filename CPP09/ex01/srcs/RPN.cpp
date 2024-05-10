/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:32 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/10 16:09:32 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>
#include <cctype>
#include <iostream>

RPN::RPN(const std::string& input) {
	if (input.size() % 2 != 1) {
		std::cout << "cc" << std::endl;
		throw wrongInput();
	}
	for (size_t i = 0; input[i] != '\0'; ++i) {
		if (i % 2 != 0) {
			if (input[i] != ' ') {
				throw wrongInput();
			}
		} else {
			if (std::isdigit(input[i]) == 0 && this->_isOp(input[i]) == 0) {
				throw wrongInput();
			} else {
				this->_input += input[i];
			}
		}
	}
	std::cout << this->_input << std::endl;
	return ;
}

RPN::RPN( void ) {
	return ;
}

RPN::~RPN( void ) {
	return ;
}

RPN::RPN(const RPN& to_copy) {
	(void)to_copy;
	return ;
}

RPN&	RPN::operator=(const RPN& rhs) {
	(void)rhs;
	return (*this);
}

int	RPN::evaluate( void ) {
	for (size_t i = 0; this->_input[i] != '\0'; ++i) {
		if (this->_input[i] > 48) {
			this->_container.push(this->_input[i] - 48);
		} else {
			if (this->_container.size() < 2) {
				std::cout << "cc " << this->_container.size() << std::endl;
				throw wrongInput();
			} else {	
				this->_doOp(this->_input[i]);
			}
		}
	}
	if (this->_container.size() != 1) {
		throw wrongInput();
		std::cout << "cc fronm end" << std::endl;
	}
	return (this->_container.top());
}

inline int	RPN::_isOp( char c ) const {
	if (c == '-' || c == '+' || c == '/' || c == '*') {
		return (1);
	} return (0);
}

inline void	RPN::_doOp( char c) {
	int	pending_numbers[2];
	
	pending_numbers[1] = this->_container.top(); 
	this->_container.pop();
	pending_numbers[0] = this->_container.top(); 
	this->_container.pop();
	switch (c) {
		case '+' :
			this->_container.push(pending_numbers[0] + pending_numbers[1]);
			break ;
		case '-' :
			this->_container.push(pending_numbers[0] - pending_numbers[1]);
			break ;
		case '*' :
			this->_container.push(pending_numbers[0] * pending_numbers[1]);
			break ;
		case '/' :
			this->_container.push(pending_numbers[0] / pending_numbers[1]);
			break ;
		default :
			break ;
	}
}

const char*		RPN::wrongInput::what() const throw() {
	return ("Error");
}
