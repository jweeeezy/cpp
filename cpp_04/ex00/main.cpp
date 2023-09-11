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

//#include "Animal.hpp" // needed for Animal class
//#include "Dog.hpp"    // needed for Dog class
//#include "Cat.hpp"    // needed for Cat class

#include "WrongAnimal.hpp" // needed for WrongAnimal class
#include "WrongCat.hpp"    // needed for WrongCat class

int	main(void)
{
	{
//		const Animal* meta = new Animal();
//		const Animal* j = new Dog();
//		const Animal* i = new Cat();
//
//		std::cout << j->getType() << " " << std::endl;
//		std::cout << i->getType() << " " << std::endl;
//		i->makeSound();
//		j->makeSound();
//		meta->makeSound();
//
//
//		delete meta;
//		delete j;
//		delete i;
	}
	
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongCat* i = new WrongCat();
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		meta->makeSound();
		i->makeSound();
		
		delete meta;
		delete i;
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
