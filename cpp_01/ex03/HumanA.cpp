
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

void	HumanA::attack( void ) const
{
	std::cout	<< name
				<< " attacks with their "
				<< weapon.getType()
				<< std::endl;
}

HumanA::HumanA(const std::string& name, Weapon& weapon)
				: name(name), weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}