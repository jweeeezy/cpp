// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  FragTrap.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "FragTrap.hpp" // needed for FragTrap class, ClapTrap class
#include <iostream>     // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap: "
		      << "High Five guys! ... "
			  << "High Five! ... "
			  << "Come on don't leave me hanging ... !"
			  << std::endl;
	return ;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);
	print_log("FragTrap: assignment operator called");
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	print_log("FragTrap: copy constructor called");
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	print_log("FragTrap: default constructor called");
	return ;
}

FragTrap::~FragTrap()
{
	print_log("FragTrap: destructor called");
	return ;
}

// -------------------------------------------------------------------------- //
