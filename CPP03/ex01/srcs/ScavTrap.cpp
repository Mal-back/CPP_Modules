/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:34:48 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/08 18:34:49 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_name = "RandomDude";
	this->_attackDamage = 20;
	this->_energyPoint = 50;
	this->_hitPoints = 100;
	return ;
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_name = name;
	this->_attackDamage = 20;
	this->_energyPoint = 50;
	this->_hitPoints = 100;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& to_copy) : ClapTrap(to_copy._name) {
	*this = to_copy;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	return ;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const& rhs) {
	if (this != &rhs) {
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	std::cout << "ScavTrap copy operator overload called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate( void ) const {
	std::cout << "ScavTrap " << this->_name << " is know in gatekeeping mode." << std::endl;
	return ;
}

void		ScavTrap::attack(std::string const& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is already dead..." << std::endl;
	} else if (this->_energyPoint > 0) {
		std::cout << "ScavTrap " << this->_name << " attack " << target
			<< " causing " << _attackDamage << " points of damage !" << std::endl;
		this->_energyPoint -= 1;
	} else {
		std::cout << "ScavTrap " << this->_name << " has no more energy\
 point to do anything !" << std::endl;
	}
	return ;
}

void	ScavTrap::printStat( void ) const {
	std::cout << "ScavTrap " << this->_name << " stats :" << std::endl;
	std::cout << "Hit points : " << this->_hitPoints << std::endl;
	std::cout << "Energy points : " << this->_energyPoint << std::endl;
	std::cout << "Attack points : " << this->_attackDamage << std::endl;
	return ;
}
