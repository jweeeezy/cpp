// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>    // needed for MACROS
#include <iostream>   // needed for std::cout, std::endl

#include "WrongAnimal.hpp" // needed for WrongAnimal class
#include "WrongCat.hpp"    // needed for WrongCat class
#include "Cat.hpp"         // needed for Cat class, Animal class
#include "Dog.hpp"         // needed for Dog class

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n" << story << " ..." << "\n" << RESET << std::endl;
}

int	main(void)
{
	print_story("const Animal* test:");
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		
		meta->makeSound();
		j->makeSound();
		i->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	
	print_story("Instance Dog/Cat test:");
	{

		Dog j;
		Cat i;

		std::cout << j.getType() << std::endl;
		std::cout << i.getType() << std::endl;

		j.makeSound();
		i.makeSound();

	}
	
		print_story("wrong Animal* test:");
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* j = new WrongCat();
		
		std::cout << meta->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << j->getType() << std::endl;

		meta->makeSound();
		i->makeSound();
		j->makeSound();
		
		delete meta;
		delete i;
		delete j;
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
