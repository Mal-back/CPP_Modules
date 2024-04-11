/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:10:42 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/09 18:10:42 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	const Animal* meta = new(std::nothrow) Animal();
	if (meta == NULL) { return (1); }
	const Animal* j = new(std::nothrow) Dog();
	if (j == NULL) {
		delete meta;
		return (1);
	}
	const Animal* i = new(std::nothrow) Cat();
	if (i == NULL) {
		delete meta;
		delete j;
		return (1);
	}
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	delete i;
	delete j;
	delete meta;

	Cat cat1;
	const Animal* dog1	= new Dog;
	if (dog1 == NULL) { return (1); }
	const WrongAnimal *humanoid_cat = new(std::nothrow) WrongCat();
	if (humanoid_cat == NULL) {
		delete dog1;
		return (1);
	}
	const WrongAnimal *random_dude = new(std::nothrow) WrongAnimal();
	if (random_dude == NULL) {
		delete dog1;
		delete humanoid_cat;
		return (1);
	}
	Animal no_type;

	no_type.makeSound();
	std::cout << no_type.getType() << " " << std::endl;
	cat1.makeSound();
	std::cout << cat1.getType() << " " << std::endl;
	dog1->makeSound();
	std::cout << dog1->getType() << " " << std::endl;
	humanoid_cat->makeSound();
	std::cout << humanoid_cat->getType() << " " << std::endl;
	random_dude->makeSound();
	std::cout << random_dude->getType() << " " << std::endl;

	delete humanoid_cat;
	delete random_dude;
	delete dog1;

	const Animal*	cat2 = new(std::nothrow) Cat(cat1);
	if (cat2 == NULL) { return (1); }
	Animal*	cat3 = new(std::nothrow) Cat(); // Creating this one as "const Animal *" 
	// would prevent copying operator to work. Uncomment line 83 to make a it work with
	// const qualifier.
	if (cat3 == NULL) {
		delete cat2;
		return (1);
	}

	// const Animal*	cat4 = new(std::nothrow) Cat(cat2); --> This doesn,t compile,
	// It is not a good idea to copy a cat by refering to a pointer that could be a dog !

	*cat3 = cat1;
	// static_cast<Animal>(*cat3) = cat1;

	cat2->makeSound();
	std::cout << cat2->getType() << " " << std::endl;
	cat3->makeSound();
	std::cout << cat3->getType() << " " << std::endl;

	delete cat2;
	delete cat3;
}
