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
#include "ScavTrap.hpp" // needed for ScavTrap class
#include "FragTrap.hpp" // needed for FragTrap class, ClapTrap class
#include <iostream>     // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n" << story << " ..." << "\n" << RESET << std::endl;
}

int	main(void)
{

	ScavTrap st("Big Brody");
	st.guardGate();

	{
		ClapTrap ct("Small Brody");
		print_story("Small Brody is visiting his bro Big Brody at his workplace");

		{
			FragTrap ft("Weird Brody");

			print_story("A stranger appears and shouts at them");
			ft.highFiveGuys();

			print_story("Big and small brody are confused. But its already too late");
			
			ft.attack(st.getName());
			st.takeDamage(ft.getAttackDamage());
			
			print_story("They left him hanging, now he wants them hanging");
			
			ft.attack(ct.getName());
			ct.takeDamage(ft.getAttackDamage());

			print_story("Big Brody has enough and wants revenge");

			while (ft.getHitPoints() != 0)
			{
				st.attack(ft.getName());
				ft.takeDamage(st.getAttackDamage());
			}
		}
		print_story("Big Brody takes a last glance at his bro Small Brody");
	}

	print_story("Even though Big Brody is sad, he still has to work");
	
	st.beRepaired(10);
	st.guardGate();
	
	print_story("Rumours say that he will continue his guard until end of time");

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
