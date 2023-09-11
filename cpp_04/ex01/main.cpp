// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cout, std::endl

#include "Cat.hpp"  // needed for Cat class, Animal class
#include "Dog.hpp"  // needed for Dog class

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n" << story << "\n" << RESET << std::endl;
}

int	main(void)
{
	
	Animal *arr[10];

	print_story("Dog construction...");
	for (int i = 0; i < 5; ++i)
	{
		arr[i] = new Dog();
	}

	print_story("Cat construction...");
	for (int i = 5; i < 10; ++i)
	{
		arr[i] = new Cat();
	}

	print_story("random array Dog testing...");
	{
		std::cout << arr[1]->getType() << std::endl;
		arr[1]->makeSound();
		static_cast<Dog*>(arr[1])->setIdea("Getting a beer for my owner", 50);
		std::cout << static_cast<Dog*>(arr[1])->getIdea(50) << std::endl;

		Dog a = *(static_cast<Dog *>(arr[1]));

		std::cout << a.getType() << std::endl;
		a.makeSound();
		std::cout << a.getIdea(50) << std::endl;
	}
	
	print_story("random array Cat testing...");
	{
		std::cout << arr[9]->getType() << std::endl;
		arr[9]->makeSound();
		static_cast<Cat*>(arr[1])->setIdea("Smacking my owner in the face", 20);
		std::cout << static_cast<Cat*>(arr[1])->getIdea(20) << std::endl;

		Cat a(*(static_cast<Cat*>(arr[9])));
		std::cout << a.getType() << std::endl;
		a.makeSound();
		std::cout << a.getIdea(20) << std::endl;
	}

	print_story("destruction...");
	for (int i = 0; i < 10; ++i)
	{
		delete arr[i];
	}

	print_story("instance testing...");
	{
		Cat j;

		std::cout << j.getType() << std::endl;
		j.makeSound();
		j.setIdea("Bring a mouse home, because my owner likes it dirty", 0);
		std::cout << j.getIdea(0) << std::endl;
	}
	
	print_story("subject test...");
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
