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
	print_log("DiamondTrap: assignment operator  called");
	this->name = rhs.name;
	ClapTrap::operator=(rhs);
	ScavTrap::operator=(rhs);
	FragTrap::operator=(rhs);
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

DiamondTrap::DiamondTrap(std::string name) : 	ClapTrap(name + "_clap_name"),
												ScavTrap(name + "_clap_name"),
												FragTrap(name + "_clap_name"),
												name(name)
{
	print_log("DiamondTrap: constructor called");
	return ;
}

DiamondTrap::DiamondTrap() : 	ClapTrap(),
								ScavTrap(),
								FragTrap(),
								name("DiamondTrap")
{
	print_log("DiamondTrap: default constructor called");
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : 	ClapTrap(src),
													ScavTrap(src),
													FragTrap(src),
													name(src.name)
{
	print_log("DiamondTrap: copy constructor called");

}

DiamondTrap::~DiamondTrap()
{
	print_log("DiamondTrap: destructor called");
	return ;
}

// -------------------------------------------------------------------------- //
