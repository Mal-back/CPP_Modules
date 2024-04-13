/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:21:14 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 15:21:14 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource( void ) : IMateriaSource() {
	for (int i = 0; i < 4; ++i) {
		this->_knownMateria[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& rhs) {
	for (int i = 0; i < 4; ++i) {
		if (rhs._knownMateria[i] != NULL) {
			this->_knownMateria[i] = rhs._knownMateria[i]->clone();
		} else {
			this->_knownMateria[i] = NULL;
		}
	}
	return ;
}

MateriaSource::~MateriaSource( void ) {
	this->_cleanTab();
	return ;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs) {
	if (this == &rhs) {
		return (*this) ;
	}
	this->_cleanTab();
	for (int i = 0; i < 4; ++i) {
		if (rhs._knownMateria[i] != NULL)
			this->_knownMateria[i] = rhs._knownMateria[i]->clone();
	}
	return (*this);
}

void	MateriaSource::_cleanTab( void ) {
	for (int i = 0; i < 4; ++i) {
		if (this->_knownMateria[i] != NULL) {
			delete this->_knownMateria[i];
			this->_knownMateria[i] = NULL;
		}
	}
	return ;
}

void	MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (this->_knownMateria[i] == NULL) {
			this->_knownMateria[i] = m;
			return ;
		}
	}	
	delete m;
	return ;
}

AMateria*	MateriaSource::createMateria(const std::string &type) const {
	for (int i = 0; i < 4; ++i) {
		if (_knownMateria[i] != NULL
				&& _knownMateria[i]->getType().compare(type) == 0) {
			return (_knownMateria[i]->clone());
		}
	}
	return (0);
}
