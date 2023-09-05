// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>         // needed for MACROS
#include "DiamondTrap.hpp" // needed for DiamondTrap class
#include <iostream>        // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n" << story << " ..." << "\n" << RESET << std::endl;
}

int	main(void)
{
	print_story("Test subject: Newly created DiamondTrap");
	
	DiamondTrap dt("Walter");
	print_story("But does he know who he is?");
	dt.whoAmI();
	
	print_story("Does he know about his roots?");
	{
		DiamondTrap dt;
		dt.whoAmI();
	}

	print_story("Does he know how to mimic himself?");
	{
		DiamondTrap dt_c=dt;
		dt_c.whoAmI();
	}

	print_story("Does he know how to cheer for his guys?");
	dt.highFiveGuys();
	
	print_story("Does he know how to guard whats precious?");
	dt.guardGate();

	print_story("Does he know how to wield a robot sword?");
	dt.attack("Dummy Target");

	print_story("Its too powerful, destroy it!");
	dt.takeDamage(200);
	dt.beRepaired(200);

	print_story("Dear god, what have we created?");
	dt.whoAmI();
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
