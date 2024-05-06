/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:57:27 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/13 15:57:28 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "Poison.hpp"
#include "Lightning.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <new>

int main( void ) {
	{
		std::cout << "Subject Tests" << std::endl << std::endl;
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << "Testing unequip and equiping too much Materia + Materias \
are destroyed with the charatcer" << std::endl << std::endl;
		MateriaSource* src = new(std::nothrow) MateriaSource();
		if (src == NULL) { return 1; }
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Fire());
		src->learnMateria(new Poison());
		ICharacter* me = new(std::nothrow) Character("me");
		if (me == NULL) {
			delete src;
			return 1;
		}
		AMateria* tmp;
		AMateria* on_the_ground;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		on_the_ground = tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("poison");
		me->equip(tmp);
		tmp = src->createMateria("fire");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		if (bob == NULL) {
			delete me;
			delete src;
			return 1;
		}
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(4, *bob);
		me->unequip(0);
		me->equip(on_the_ground);
		me->unequip(0);
		me->unequip(0);
		delete bob;
		delete me;
		delete src;
		if (tmp != NULL) {
			delete tmp;
		}
		if (on_the_ground != NULL) {
			delete on_the_ground;
		}
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << "Materia source is capped at 4 materias" << std::endl << std::endl;
		MateriaSource* src = new(std::nothrow) MateriaSource();
		if (src == NULL) { return 1; }
		src->learnMateria(new Ice());
		src->learnMateria(new Fire());
		src->learnMateria(new Poison());
		src->learnMateria(new Lightning());
		src->learnMateria(new Cure());
		ICharacter* me = new(std::nothrow) Character("me");
		if (me == NULL) {
			delete src;
			return 1;
		}
		ICharacter* bob = new Character("bob");
		if (bob == NULL) {
			delete me;
			delete src;
			return 1;
		}
		AMateria* tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = NULL;
		me->use(0, *bob);
		tmp = src->createMateria("lightning");
		me->equip(tmp);
		tmp = NULL;
		tmp = src->createMateria("fire");
		me->equip(tmp);
		tmp = NULL;
		tmp = src->createMateria("poison");
		me->equip(tmp);
		tmp = NULL;
		tmp = src->createMateria("lightning");
		me->equip(tmp);
		tmp = NULL;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		delete bob;
		delete me;
		delete src;
		if (tmp != NULL) {
			delete tmp;
		}
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << "Re-assignation doesn't create leak" << std::endl << std::endl;
		MateriaSource* src = new(std::nothrow) MateriaSource();
		if (src == NULL) { return 1; }
		MateriaSource* src2 = new(std::nothrow) MateriaSource();
		if (src2 == NULL) {
			delete src;
			return (1);
		}
		Character* me = new(std::nothrow) Character("me");
		if (me == NULL) {
			delete src;
			delete src2;
			return (1);
		}
		Character* you = new(std::nothrow) Character("you");
		if (you == NULL) {
			delete me;
			delete src;
			delete src2;
			return (1);
		}
		AMateria* tmp;
		src->learnMateria(new Ice());
		src->learnMateria(new Fire());
		src->learnMateria(new Poison());
		src->learnMateria(new Lightning());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Cure());
		tmp = src2->createMateria("cure");
		you->equip(tmp);
		tmp = NULL;
		tmp = src2->createMateria("cure");
		you->equip(tmp);
		tmp = NULL;
		tmp = src2->createMateria("cure");
		you->equip(tmp);
		tmp = NULL;
		tmp = src2->createMateria("cure");
		you->equip(tmp);
		tmp = NULL;
		you->use(2, *me);
		*src2 = *src;
		delete src;
		tmp = src2->createMateria("fire");
		me->equip(tmp);
		tmp = NULL;
		tmp = src2->createMateria("lightning");
		me->equip(tmp);
		tmp = NULL;
		tmp = src2->createMateria("poison");
		me->equip(tmp);
		tmp = NULL;
		tmp = src2->createMateria("fire");
		me->equip(tmp);
		tmp = NULL;
		*you = *me;
		me->use(0, *you);
		you->use(0, *me);
		me->use(1, *you);
		you->use(1, *me);
		me->use(2, *you);
		you->use(2, *me);
		me->use(3, *you);
		you->use(3, *me);
		delete me;
		delete you;
		// delete src;
		delete src2;
	}
	return 0;
}
