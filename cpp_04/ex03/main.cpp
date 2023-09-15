// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>           // needed for MACROS
#include <iostream>          // needed for std::cout, std::endl

#include "Ice.hpp"           // needed for Ice class
#include "Cure.hpp"          // needed for Cure class
#include "Floor.hpp"         // needed for Floor class
#include "Character.hpp"     // needed for Character class, ICharacter interface
#include "MateriaSource.hpp" // needed for MateriaSource class, AMateria class
                             // IMateriaSource interface

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n< " << story << " >\n" << RESET << std::endl;
}

static inline void print_hint(std::string story)
{
	std::cout << GREEN << story << RESET << std::endl;
}

int	main(void)
{
	print_story("Subject tests");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	print_story("AMateria class tests");
	{
		Ice ice;
		Cure cure;
		ICharacter* target = new Character("target");

		std::cout << ice.getType() << std::endl;
		std::cout << cure.getType() << std::endl;

		ice.use(*target);
		cure.use(*target);

		target->equip(ice.clone());
		target->use(0, *target);
		delete target;
	}

	print_story("MateriaSource class tests");
	{
		MateriaSource src;
		src.showStorage();

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(NULL);
		src.learnMateria(new Cure()); //  put into first empty spot

		src.showStorage();

		print_hint("                                    <--- Copy constructor");
		MateriaSource cpy(src);
		cpy.showStorage();

		
		print_hint("                                 <--- assignment operator");
		MateriaSource aopr;
		aopr = cpy;
		aopr.showStorage();

		
		print_hint("                                            <--- cleaning");
		src.cleanStorage();
		src.showStorage();

		print_hint("                                      <--- deep copy test");
		cpy.showStorage();
		aopr.showStorage();
	}

	print_story("Character class tests");
	{
		Character tim("Tim");
		Character albert("Albert");
		AMateria* ice = new Ice(); 

		tim.showInventory();
		print_hint("                                          <--- equip test");
		tim.equip(ice);
		tim.showInventory();
		std::cout << tim.getItem(0) << std::endl;
		std::cout << tim.getItem(1) << std::endl;
		print_hint("                                            <--- use test");
		tim.use(0, tim);
		tim.use(1, tim);

		print_hint("                                    <--- Copy constructor");
		Character cpy(tim);
		std::cout << cpy.getName() << std::endl;

		print_hint("                                 <--- assignment operator");
		albert = tim;
		std::cout << albert.getName() << std::endl;

		print_hint("                                            <--- cleaning");
		tim.clearInventory();
		tim.showInventory();

		print_hint("                                      <--- deep copy test");
		albert.showInventory();
		cpy.showInventory();
	}
	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
