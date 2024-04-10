/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:37:22 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 19:37:23 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "RandomDude";
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoints = 100;
	return ;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_name = name;
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoints = 100;
	return ;
}

FragTrap::FragTrap(const FragTrap& to_copy) : ClapTrap(to_copy._name) {
	*this = to_copy;
	std::cout << "FragTrap copy constructor called" << std::endl;
	return ;
}

FragTrap&		FragTrap::operator=(FragTrap const& rhs) {
	if (this != &rhs) {
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	std::cout << "FragTrap copy operator overload called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFiveGuys( void ) const {
	std::cout << "FragTrap " << this->_name << " want to highfive his mates !" << std::endl;
	return ;
}

void	FragTrap::printStat( void ) const {
	std::cout << "FragTrap " << this->_name << " stats :" << std::endl;
	std::cout << "Hit points : " << this->_hitPoints << std::endl;
	std::cout << "Energy points : " << this->_energyPoint << std::endl;
	std::cout << "Attack points : " << this->_attackDamage << std::endl;
	return ;
}
