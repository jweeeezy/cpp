// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>      // needed for MACROS
#include "ClapTrap.hpp" // needed for ClapTrap class
#include <iostream>     // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

static void print_test(std::string message)
{
	std::cout << GREEN << "\n" << message << "\n" << RESET << std::endl;
}

int	main(void)
{
	print_test("standard behaviour test");
	{
		ClapTrap first("Hulk");
		ClapTrap second("Bulk");

		first.attack(second.getName());
		second.takeDamage(first.getAttackDamage());
		second.beRepaired(0);
	}
	
	print_test("manual hp test");
	{
		ClapTrap first("Shulk");
		ClapTrap second("Yulk");

		first.takeDamage(10);
		first.attack(second.getName());
		second.takeDamage(first.getAttackDamage());
	}

	print_test("manual energy + copy constructor test");
	{
		ClapTrap first("Zulk");
		ClapTrap copy(first);

		for (size_t i = 0; i < 10; ++i)
		{
			first.attack(copy.getName());
			copy.takeDamage(first.getAttackDamage());
		}
		first.beRepaired(5);
		first.attack(copy.getName());
		copy.takeDamage(first.getAttackDamage());
	}

	std::cout << std::endl;

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
