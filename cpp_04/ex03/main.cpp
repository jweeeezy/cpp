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

#include "Ice.hpp"       // needed for Ice class
#include "Cure.hpp"      // needed for Cure class
#include "Floor.hpp"     // needed for Floor class
#include "Character.hpp" // needed for Character class
#include "MateriaSource.hpp" // needed for MateriaSource class

int	main(void)
{
	Character a("Andrew");
	
	AMateria* i1 = new Ice();
	AMateria* i2 = new Ice();
	AMateria* i3 = new Cure();
	AMateria* i4 = new Cure();

	a.equip(i1);
	a.equip(i2);
	a.equip(i3);
	a.equip(i4);
	
	a.showInventory();

	Character b("Bob");

	b = a;

	b.showInventory();
	b.clearInventory();
	b.showInventory();

	Character c(b);

	c.showInventory();



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
