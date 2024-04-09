/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:39:21 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 16:39:22 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ): _name("RandomDude"), _attackDamage(0),
	_hitPoints(10), _energyPoint(10) {
		std::cout << "ClapTrap Default constructor called" << std::endl;
		return ;
	}

ClapTrap::ClapTrap( std::string const name): _name(name), _attackDamage(0),
	_hitPoints(10), _energyPoint(10) {
		std::cout << "ClapTrap Name constructor called" << std::endl;
		return ;
	}

ClapTrap::ClapTrap( ClapTrap const& to_copy) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = to_copy;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Destructor Called." << std::endl;
	return;
}

ClapTrap&		ClapTrap::operator=(ClapTrap const& rhs) {
	if (this != &rhs) {
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	std::cout << "ClapTrap copy operator overload called" << std::endl;
	return (*this);
}

void		ClapTrap::attack(std::string const& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead..." << std::endl;
	} else if (this->_energyPoint > 0) {
		std::cout << "ClapTrap " << this->_name << " attack " << target
			<< " causing " << _attackDamage << " points of damage !" << std::endl;
		this->_energyPoint -= 1;
	} else {
		std::cout << "ClapTrap " << this->_name << " has no more energy\
 point to do anything !" << std::endl;
	}
	return ;
} 

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage. ";
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " died from damage taken..." << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name << " has know " 
			<< this->_hitPoints << " hit points remaining." << std::endl;	
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoint == 0) {
		std::cout << "ClapTrap " << this->_name << " has no more energy\
 point to do anything !" << std::endl;
		return ;
	} else if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was repaired of " << amount << " .";
	_hitPoints += amount;
	_energyPoint -= 1;
	std::cout << " He know has " << this->_hitPoints << " hit points." << std::endl;
}

void	ClapTrap::printStat( void ) const {
	std::cout << "ClapTrap " << this->_name << " stats :" << std::endl;
	std::cout << "Hit points : " << this->_hitPoints << std::endl;
	std::cout << "Energy points : " << this->_energyPoint << std::endl;
	std::cout << "Attack points : " << this->_attackDamage << std::endl;
	return ;
}
