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

void	clean_array(Animal *array[], int n) {
		for (int i = 0; i < n; ++i) {
			delete array[i];
		}
	}

int main()
{
	{
		std::cout << "Tests from subject :" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	{
		std::cout << "Testing array of animal objects :" << std::endl;
		int size_of_arr = 19;
		Animal *array[size_of_arr];
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
		clean_array(array, size_of_arr);
	}
	return (0);
}
