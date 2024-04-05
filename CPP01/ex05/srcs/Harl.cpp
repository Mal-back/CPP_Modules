/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:41:36 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/05 12:41:37 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ( const char **levels ) : _levels(levels) {
	_complain_ptr[0] = &Harl::_debug;
	_complain_ptr[1] = &Harl::_info;
	_complain_ptr[2] = &Harl::_warning;
	_complain_ptr[3] = &Harl::_error;
	return ;
}

Harl::~Harl ( void ) {
	return ;
}

void	Harl::complain(std::string level) {
	int	i = 0;
	while(level.compare(_levels[i]) != 0) { ++i; }
	(this->*_complain_ptr[i])();
	return ;
}

void	Harl::_debug( void ) const {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::_info( void ) const {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::_warning( void ) const {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\
years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::_error( void ) const {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}
