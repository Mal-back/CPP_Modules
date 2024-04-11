/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:18 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/10 18:32:20 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <new>

void	clean_array(const Animal *array[], int n) {
		for (int i = 0; i < n; ++i) {
			delete array[i];
		}
	}

int main()
{
	{
		std::cout << "Tests from subject :" << std::endl << std::endl << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
		std::cout << std::endl << std::endl << std :: endl; 
	}
	{
		std::cout << "Testing array of animal objects :" << std::endl;
		std::cout << std::endl << std::endl; 
		int size_of_arr = 19;
		const Animal *array[size_of_arr];
		for (int i = 0; i < size_of_arr / 2; ++i) {
			array[i] = new(std::nothrow) Dog(); 
			if (array[i] == NULL) {
				clean_array(array, i);
				return (1);
			}
		}

		for (int i = size_of_arr / 2; i < size_of_arr; ++i) {
			array[i] = new Cat();
			if (array[i] == NULL) {
				clean_array(array, i);
				return (1);
			}
		}

		for (int i = 0; i < size_of_arr; ++i) {
			if (array[i]->getBrainIntegrity() == false) {
				clean_array(array, size_of_arr);
				return (1);
			}
		}

		for (int i = 0; i < size_of_arr; ++i) {
			array[i]->makeSound();
		}
		for (int i = 0; i < size_of_arr; ++i) {
			array[i]->printBrainAdress();
		}
		for (int i = 0; i < size_of_arr; ++i) {
			array[i]->set_idea("I'm sooooooo hungry");
		}
		for (int i = 0; i < size_of_arr; ++i) {
			array[i]->print_idea(0);
		}
		clean_array(array, size_of_arr);
		std::cout << std::endl << std::endl << std :: endl; 
	}
	// Below Scope doesn't compile anymore !
	// {
	// 	std::cout << "Abstract animals cannot manage ideas :" << std::endl;
	// 	std::cout << std::endl << std::endl; 
	// 	Animal abstract_animal;
	//
	// 	if (abstract_animal.getBrainIntegrity() == false) { return (1); }
	// 	abstract_animal.set_idea("blblblbblh");
	// 	abstract_animal.print_idea(1);
	// 	abstract_animal.print_idea_list();
	// }
	{
		std::cout << std::endl << std::endl << std :: endl; 
		std::cout << "Testing ideas behaviour :" << std::endl;
		std::cout << std::endl << std :: endl; 
		const Animal*	animals[] = {new(std::nothrow) Cat(), new(std::nothrow) Dog()};
		if (animals[0] == NULL) { return (1); }
		if (animals[0]->getBrainIntegrity() == false) {
			delete animals[0];
			return (1);
		}
		if (animals[1] == NULL) {
			delete animals[0];
			return (1);
		}
		if (animals[1]->getBrainIntegrity() == false) {
			clean_array(animals, 2);
		}
		animals[0]->set_idea("I'm going to pee on the bed");
		animals[0]->set_idea("I'm going to scratch the curtains");
		animals[0]->set_idea("Where is my human ? I'm so hungry ...");
		animals[0]->set_idea("A dog ! I should go in a fight");
		animals[0]->set_idea("Let's broke this mug on the table");
		animals[1]->set_idea("My human is gone for the day, i'm so lonely ...");
		animals[1]->set_idea("I need to pee ! I should go outside");
		animals[1]->set_idea("My human fed me ! He really is a god on earth");
		animals[1]->set_idea("This cat scares me ...");
		animals[1]->set_idea("Omg ! The human throw a ball !!!");
		std::cout << "Printing ideas from animal[0] (cat)" << std::endl;
		animals[0]->print_idea_list();
		std::cout << "Printing ideas from animal[1] (dog)" << std::endl;
		animals[1]->print_idea_list();
		clean_array(animals, 2);
		std::cout << std::endl << std::endl << std :: endl; 
	}
	{
		std::cout << "Testing deep copies :" << std::endl;
		std::cout << std::endl << std :: endl; 
		Dog *dog1 = new Dog;
		if (dog1 == NULL) { return (1); }
		if (dog1->getBrainIntegrity() == false) {
			delete dog1;
			return (1);
		}
		dog1->set_idea("My human is gone for the day, i'm so lonely ...");
		dog1->set_idea("I need to pee ! I should go outside");
		dog1->set_idea("My human fed me ! He really is a god on earth");
		dog1->set_idea("This cat scares me ...");
		dog1->set_idea("Omg ! The human throw a ball !!!");
		Dog	*dog2 = new Dog(*dog1);
		if (dog2 == NULL) { 
			delete dog1;
			return (1);
		}
		if (dog1->getBrainIntegrity() == false) {
			delete dog1;
			delete dog2;
			return (1);
		}
		std::cout << std::endl;
		std::cout << "dog2 has been built as a copy of dog1" << std::endl;
		std::cout << std::endl;
		std::cout << "Printing dog1 brain address :" << std::endl;
		dog1->printBrainAdress();
		std::cout << std::endl;
		std::cout << "Printing dog2 brain address :" << std::endl;
		dog2->printBrainAdress();
		std::cout << std::endl;
		std::cout << "Printing dog1 ideas :" << std::endl;
		std::cout << std::endl;
		dog1->print_idea_list();
		std::cout << std::endl;
		std::cout << "Printing dog2 ideas :" << std::endl;
		std::cout << std::endl;
		dog2->print_idea_list();
		std::cout << std::endl;
		std::string new_idea = "I must catch the ball !";
		std::cout << "Adding dog2 ideas" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 5; ++i) {
			dog2->set_idea(new_idea);
			new_idea += " I must catch the ball !";
		}
		std::cout << "Printing dog1 ideas :" << std::endl;
		std::cout << std::endl;
		dog1->print_idea_list();
		std::cout << std::endl;
		std::cout << "Printing dog2 ideas :" << std::endl;
		std::cout << std::endl;
		dog2->print_idea_list();
		std::cout << std::endl;
		std::cout << "Trying to add more than 100 ideas to dog 2" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 105; ++i) {
			dog2->set_idea("My human is the best !");
		}
		std::cout << std::endl << "Printing dog2 ideas :" << std::endl;
		std::cout << std::endl;
		dog2->print_idea_list();
		delete dog1;
		delete dog2;
	}
	return (0);
}
