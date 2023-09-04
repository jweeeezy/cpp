// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ClapTrap.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ClapTrap.hpp" // needed for ClapTrap class, std::string
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
	std::cout << "ClapTrap: " << name << " has no energy points left!" << std::endl;
}

static inline void print_no_hp(std::string name)
{
	std::cout << "ClapTrap: " << name << " has no hit points left!" << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

std::string ClapTrap::getName(void) const
{
	return(name);
}

short int   ClapTrap::getEnergyPoints(void) const
{
	return(energy_points);
}

short int   ClapTrap::getHitPoints(void) const
{
	return(hit_points);
}

short int ClapTrap::getAttackDamage(void) const
{
	if (energy_points <= 0 || hit_points <= 0)
	{
		return (0);
	}
	return(attack_damage);
}

void ClapTrap::attack(const std::string& target)
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
		std::cout << "ClapTrap: "
			      << this->name
				  << " attacks "
				  << target
				  << " for "
				  << this->attack_damage
				  << std::endl;
	}
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= 0)
	{
		print_no_energy(this->name);
	}
	else
	{
		energy_points -= 1;
		hit_points += amount;
		if (hit_points > 10)
		{
			hit_points = 10;
		}
		std::cout << this->name
				  << " repairs itself for "
				  << amount
				  << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
	std::cout << this->name
              << " takes "
			  << amount
			  << " damage"
			  << std::endl;
	if (hit_points <= 0)
	{
		hit_points = 0;
		std::cout << this->name 
			      << " has no hit points left!"
				  << std::endl;
	}
	return ;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloading */

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		hit_points = rhs.hit_points;
		energy_points = rhs.energy_points;
		attack_damage = rhs.attack_damage;
	}
	return (*this);
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

ClapTrap::ClapTrap(std::string name) : name(name),
	                                   hit_points(10),
	                                   energy_points(10),
									   attack_damage(0)
{
	print_log("ClapTrap: constructor called");
	return ;
}

ClapTrap::ClapTrap(void) : name("ClapTrap"),
                           hit_points(10),
						   energy_points(10),
						   attack_damage(0)
{
	print_log("ClapTrap: default constructor called");
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& src) : name(src.name), 
	                                      hit_points(src.hit_points), 
										  energy_points(src.energy_points), 
										  attack_damage(src.attack_damage)
{
	print_log("ClapTrap: copy constructor called");
	return ;
}

ClapTrap::~ClapTrap()
{
	print_log("ClapTrap: destructor called");
	return ;
}

// -------------------------------------------------------------------------- //
