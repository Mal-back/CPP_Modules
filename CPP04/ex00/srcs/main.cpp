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

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	Cat cat1;
	Dog	dog1;
	WrongCat humanoid_cat;
	Animal no_type;

	no_type.makeSound();
	cat1.makeSound();
	dog1.makeSound();
	humanoid_cat.makeSound();

	Cat cat2;
	cat2 = cat1;
	Dog dog2(dog1);

	cat2.makeSound();
	dog2.makeSound();
}
