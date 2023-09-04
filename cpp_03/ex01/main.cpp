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
#include "ScavTrap.hpp" // needed for ScavTrap class, ClapTrap class
#include <iostream>     // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	ScavTrap st("Big Brody");

	st.guardGate();

	{
		ClapTrap ct("Brody");

		std::cout << GREEN
				  << "\n\nIn a world of ClapTraps, far, far away... "
				  << ct.getName() 
				  << " is approaching the gate, that "
				  << st.getName()
				  << " is guarding..."
				  << RESET
				  << "\n\n"
				  << std::endl;
		ct.attack(st.getName());
		st.takeDamage(ct.getAttackDamage());
		st.attack(ct.getName());
		ct.takeDamage(st.getAttackDamage());
	}
	st.guardGate();
	st.beRepaired(0);

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
