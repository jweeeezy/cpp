// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ScavTrap.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ScavTrap.hpp" // needed for ScavTrap class, ClapTrap class
#include <iostream>     // needed for std::cout, std::endl
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

static inline void print_no_energy(std::string name)
{
	std::cout << "ScavTrap: " << name << " has no energy points left!" 
	<< std::endl;
}

static inline void print_no_hp(std::string name)
{
	std::cout << "ScavTrap: " << name << " has no hit points left!"
	<< std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void ScavTrap::guardGate(void)
{
	std::cout << this->name << " is guarding the gate" << std::endl;
	return ;
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points <= 0)
	{
		print_no_energy(this->name);
	}
	else if (hit_points <= 0)
	{
		print_no_hp(this->name);
	}
	else
	{
		energy_points -= 1;
		std::cout << "ScavTrap: "
                  << this->name
				  << " attacks "
				  << target
				  << " for "
				  << this->attack_damage
				  << std::endl;
	}
	return ;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	print_log("ScavTrap: Copy constructor called");
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	print_log("ScavTrap: Default constructor called");
	return ;
}

ScavTrap::~ScavTrap()
{
	print_log("ScavTrap: destructor called");
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	ClapTrap::operator=(rhs);
	print_log("ScavTrap assignment operator called");
	return *this;
}

// -------------------------------------------------------------------------- //
