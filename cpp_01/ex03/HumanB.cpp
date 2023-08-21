
#include <string>
#include <iostream>
#include "HumanB.hpp"

void	HumanB::attack( void ) const
{
	std::cout	<< name
				<< " attacks with their "
				<< weapon->getType()
				<< std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	return ;
}

HumanB::HumanB(const std::string& name) : name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}
