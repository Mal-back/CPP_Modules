
#include "Cat.hpp"
#include "Dog.hpp"
#include <new>

int main(void) {
	Cat cat;
	Cat cat2;

	cat = cat2;

	std::cout << "lala" << std::endl;
	return 0;
}
