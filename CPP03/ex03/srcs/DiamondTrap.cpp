/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:10:44 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 14:10:45 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	ScavTrap::_energyPoint;
int	FragTrap::_hitPoints;
int	FragTrap::_attackDamage;

DiamondTrap::DiamondTrap( void ) : 
	 FragTrap(), ScavTrap() {
		std::cout << "DiamondTrap name constructor called" << std::endl;
		DiamondTrap::_name = "random_dude";
		ClapTrap::_name = "random_dude_clap_trap";
		DiamondTrap::_hitPoints = this->FragTrap::_hitPoints;
		DiamondTrap::_energyPoint = this->ScavTrap::_energyPoint;
		DiamondTrap::_attackDamage = this->FragTrap::_attackDamage;
	}

DiamondTrap::DiamondTrap(const std::string& name) : 
	FragTrap(name), ScavTrap(name) {
		std::cout << "DiamondTrap name constructor called" << std::endl;
		DiamondTrap::_name = name;
		ClapTrap::_name = name + "_clap_trap";
		DiamondTrap::_hitPoints = this->FragTrap::_hitPoints;
		DiamondTrap::_energyPoint = this->ScavTrap::_energyPoint;
		DiamondTrap::_attackDamage = this->FragTrap::_attackDamage;
	}

DiamondTrap::DiamondTrap(const DiamondTrap& to_copy) :
	FragTrap(to_copy._name), ScavTrap(to_copy._name) {
	*this = to_copy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

DiamondTrap&		DiamondTrap::operator=(DiamondTrap const& rhs) {
	if (this != &rhs) {
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_hitPoints = rhs._hitPoints;
		this->DiamondTrap::_name = rhs._name;
		this->ClapTrap::_name = rhs._name + "_clap_trap";
	}
	std::cout << "DiamondTrap copy operator overload called" << std::endl;
	return (*this);
}

void	DiamondTrap::guardGate( void ) {
	std::cout << "DiamondTrap " << this->_name << " is know in gatekeeping mode." << std::endl;
	return ;
}

void		DiamondTrap::attack(std::string const& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {	
	if (this->_hitPoints == 0) {
		std::cout << "DiamondTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->_name << " took " << amount << " damage. ";
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0) {
		this->_hitPoints = 0;
		std::cout << "DiamondTrap " << this->_name << " died from damage taken..." << std::endl;
	} else {
		std::cout << "DiamondTrap " << this->_name << " has know " 
			<< this->_hitPoints << " hit points remaining." << std::endl;	
	}
	return ;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoint == 0) {
		std::cout << "DiamondTrap " << this->_name << " has no more energy\
 point to do anything !" << std::endl;
		return ;
	} else if (this->_hitPoints == 0) {
		std::cout << "DiamondTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->_name << " was repaired of " << amount << " .";
	_hitPoints += amount;
	_energyPoint -= 1;
	std::cout << " He know has " << this->_hitPoints << " hit points." << std::endl;
}

void	DiamondTrap::printStat( void ) const {
	std::cout << "DiamondTrap " << this->_name << " stats :" << std::endl;
	std::cout << "Hit points : " << this->DiamondTrap::_hitPoints << std::endl;
	std::cout << "Energy points : " << this->ScavTrap::_energyPoint << std::endl;
	std::cout << "Attack points : " << this->_attackDamage << std::endl;
	return ;
}

void	DiamondTrap::whoAmI( void ) const {
	std::cout << "who am I ? My name is " << DiamondTrap::_name << ", but my other name is "
		<< ClapTrap::_name << " ..." << std::endl;
}

void	DiamondTrap::highFiveGuys( void ) const {
	std::cout << "DiamondTrap " << this->_name << " want to highfive his mates !" << std::endl;
	return ;
}

