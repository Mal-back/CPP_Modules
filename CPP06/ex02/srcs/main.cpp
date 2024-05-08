/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:23:55 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 19:23:55 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <new>

Base *generate( void ) {
	Base *ptr = NULL;
	srand((unsigned int)time(NULL));
	switch(rand() % 3) {
		case 0:
			std::cout << "From generate : Creating a new A object" << std::endl;
			return (ptr = new(std::nothrow) A);
			break ;
		case 1:
			std::cout << "From generate : Creating a new B object" << std::endl;
			return (ptr = new(std::nothrow) B);
			break ;
		case 2:
			std::cout << "From generate : Creating a new C object" << std::endl;
			return (ptr = new(std::nothrow) C);
			break ;
		default :
			return (NULL);
			break ;
	}
}

void	identify(Base *ptr) {
	if (dynamic_cast<A *>(ptr) != NULL) {
		std::cout << "From identify through ptr : object type is A" << std::endl; 
	} else if (dynamic_cast<B *>(ptr) != NULL) {
		std::cout << "From identify through ptr : object type is B" << std::endl; 
	} else if (dynamic_cast<C *>(ptr) != NULL) {
		std::cout << "From identify through ptr : object type is C" << std::endl; 
	}
}
void	identify(Base& ptr) {
	try {
		ptr = dynamic_cast<A&>(ptr);
		std::cout << "From identify through ref : object type is A" << std::endl; 
		return ;
	} catch (std::exception& e) {}	
	try {
		ptr = dynamic_cast<B&>(ptr);
		std::cout << "From identify through ref : object type is B" << std::endl; 
		return ;
	} catch (std::exception& e) {}	
	try {
		ptr = dynamic_cast<C&>(ptr);
		std::cout << "From identify through ref : object type is C" << std::endl; 
		return ;
	} catch (std::exception& e) {}	
}

int main(void) {
	Base *ptr = generate();
	if (ptr == NULL) {return (1);}
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
