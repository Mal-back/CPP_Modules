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

FragTrap::FragTrap(std::string const& name) : ClapTrap() {
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_name = name;
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoints = 100;
	return ;
}

FragTrap::FragTrap(const FragTrap& to_copy) : ClapTrap() {
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

void	FragTrap::highFiveGuys( void ) {
	std::cout << "FragTrap " << this->_name << " want to highfive his mates !" << std::endl;
	return ;
}

void		FragTrap::attack(std::string const& target) {
	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is already dead..." << std::endl;
	} else if (this->_energyPoint > 0) {
		std::cout << "FragTrap " << this->_name << " attack " << target
			<< " causing " << _attackDamage << " points of damage !" << std::endl;
		this->_energyPoint -= 1;
	} else {
		std::cout << "FragTrap " << this->_name << " has no more energy\
 point to do anything !" << std::endl;
	}
	return ;
}

void	FragTrap::takeDamage(unsigned int amount) {
	
	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " took " << amount << " damage. ";
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0) {
		this->_hitPoints = 0;
		std::cout << "FragTrap " << this->_name << " died from damage taken..." << std::endl;
	} else {
		std::cout << "FragTrap " << this->_name << " has know " 
			<< this->_hitPoints << " hit points remaining." << std::endl;	
	}
	return ;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoint == 0) {
		std::cout << "FragTrap " << this->_name << " has no more energy\
 point to do anything !" << std::endl;
		return ;
	} else if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " was repaired of " << amount << " .";
	_hitPoints += amount;
	_energyPoint -= 1;
	std::cout << " He know has " << this->_hitPoints << " hit points." << std::endl;
}
