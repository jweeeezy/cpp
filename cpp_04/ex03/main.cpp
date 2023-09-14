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
	Floor fl;

	AMateria* a = new Ice();
	AMateria* b = new Ice();
	AMateria* c = new Cure();
	AMateria* d = new Cure();
	AMateria* e = new Cure();
	AMateria* f = new Cure();

	AMateria* g = new Cure();

	fl.add(a);
	fl.add(b);
	fl.add(c);
	fl.add(d);
	fl.add(e);
	fl.add(f);

	fl.print();

	fl.add(g);

	fl.print();

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
