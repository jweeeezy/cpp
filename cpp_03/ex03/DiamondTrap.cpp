// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  DiamondTrap.cpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "DiamondTrap.hpp" // needed for DiamondTrap class, FragTrap class
						   // ScavTrap class, ClapTrap class, std::string
#include <iostream>        // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void DiamondTrap::whoAmI(void)
{
	std::cout << "My names are "
				<< this->name 
				<< " and "
				<< this->ClapTrap::name
				<< std::endl;
	return ;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	(void) rhs;
	print_log("DiamondTrap: assignment operator  called");
	return *this;
}

DiamondTrap::DiamondTrap() : 	ClapTrap("ClapTrap"),
								ScavTrap("ScavTrap"),
								FragTrap("FragTrap"),
								name("DiamondTrap")
{
	print_log("DiamondTrap: default constructor called");
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
	(void) src;
	print_log("DiamondTrap: copy constructor called");
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : 	ClapTrap(name + "_clap_name"),
												ScavTrap(name),
												FragTrap(name),
												name(name)
{
	print_log("DiamondTrap: constructor called");
	return ;
}

DiamondTrap::~DiamondTrap()
{
	print_log("DiamondTrap: destructor called");
	return ;
}

// -------------------------------------------------------------------------- //
