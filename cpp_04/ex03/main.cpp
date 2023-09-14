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

#include "Character.hpp" // needed for Character class
#include "Ice.hpp"       // needed for Ice class
#include "Cure.hpp"      // needed for Cure class
#include "MateriaSource.hpp" // needed for MateriaSource class

#define FLOOR_SIZE 256
#define EMPTY NULL

static void prepare_floor(AMateria **floor)
{
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		floor[i] = NULL;
	}
}

void clean_floor(AMateria** floor)
{
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (floor[i] != NULL)
		{
			delete floor[i];
			floor[i] = EMPTY;
		}
	}
}

void add_floor(AMateria** floor, AMateria* drop)
{
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (floor[i] == EMPTY)
		{
			floor[i] = drop;
			return ;
		}
	}
	delete drop;
}

int	main(void)
{
	AMateria* floor[FLOOR_SIZE];
	prepare_floor(floor);

	MateriaSource src;

	src.showStorage();
	src.learnMateria(new Cure());
	src.showStorage();

	Character* harald = new Character("Harald");

	harald->showInventory();
	harald->equip(src.createMateria("ice"));
	harald->showInventory();

	ICharacter* peter = new Character("Peter");

	harald->use(0, *peter);
	add_floor(floor, harald->getItem(0));
	harald->unequip(0);

	clean_floor(floor);

	delete peter;
	delete harald;

//	IMateriaSource* src = new MateriaSource();
//	src->learnMateria(new Ice());
//	src->learnMateria(new Cure());
//
//	ICharacter* me = new Character("me");
//
//	AMateria* tmp;
//	tmp = src->createMateria("ice");
//	me->equip(tmp);
//	tmp = src->createMateria("cure");
//	me->equip(tmp);
//
//	ICharacter* bob = new Character("bob");
//
//	me->use(0, *bob);
//	me->use(1, *bob);
//
//	delete bob;
//	delete me;
//	delete src;

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
