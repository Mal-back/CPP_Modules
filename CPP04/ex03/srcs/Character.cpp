/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:32:08 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/12 19:32:08 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( void ) : ICharacter(), _name("RandomDude") {
	for (int i = 0; i < 4; ++i) {
		_materiaTab[i] = NULL;
	}
	return ;
}

Character::Character( const std::string& name ) : ICharacter(), _name(name) {
	for (int i = 0; i < 4; ++i) {
		_materiaTab[i] = NULL;
	}
	return ;
}

Character::Character( const Character& to_copy ) : ICharacter(), _name(to_copy.getName()) {
	this->_copyMateria(to_copy);
	return ;
}

Character::~Character( void ) {
	for (int i = 0; i < 4; ++i) {
		if (_materiaTab[i] != NULL) {
			delete _materiaTab[i];
		}
	}
}

Character&	Character::operator=(const Character& rhs) {
	if (this == &rhs) {
		return (*this);
	}
	for (int i = 0; i < 4; ++i) {
		if (this->_materiaTab[i] != NULL) {
			delete _materiaTab[i];
		}
	}
	this->_copyMateria(rhs);
	return (*this);
}

void	Character::_copyMateria(const Character& src) {
	for (int i = 0; i < 4; ++i) {
		if (src._materiaTab[i] != NULL) {
			this->_materiaTab[i] = src._materiaTab[i]->clone();
		} else {
			this->_materiaTab[i] = NULL;
		}
	}
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (this->_materiaTab[i] == NULL) {
			this->_materiaTab[i] = m;
			break;
		}
	}
	return ;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		return ;
	}
	this->_materiaTab[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || _materiaTab[idx] == NULL) {
		return ;
	}
	this->_materiaTab[idx]->use(target);
	delete this->_materiaTab[idx];
	this->_materiaTab[idx] = NULL;
}

const std::string&	Character::getName( void ) const {
	return(this->_name);
}
