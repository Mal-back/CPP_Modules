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

DiamondTrap::DiamondTrap( void ) : 
	 FragTrap(), ScavTrap() {
		std::cout << "DiamondTrap name constructor called" << std::endl;
		DiamondTrap::_name = "random_dude";
		ClapTrap::_name = "random_dude_clap_trap";
		DiamondTrap::_hitPoints = this->getBaseHitPoints();
		DiamondTrap::_energyPoint = this->ScavTrap::_energyPoint;
		DiamondTrap::_attackDamage = this->getBaseAttackDamage();
	}

DiamondTrap::DiamondTrap(const std::string& name) : 
	FragTrap(name), ScavTrap(name) {
		std::cout << "DiamondTrap name constructor called" << std::endl;
		DiamondTrap::_name = name;
		ClapTrap::_name = name + "_clap_trap";
		DiamondTrap::_hitPoints = this->getBaseHitPoints();
		DiamondTrap::_energyPoint = this->ScavTrap::_energyPoint;
		DiamondTrap::_attackDamage = this->getBaseAttackDamage();
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
