
#include "Weapon.hpp"

const std::string& Weapon::getType( void ) const
{
	return (type);
}

void	Weapon::setType( std::string new_type)
{
	this->type = new_type;
	return ;
}

Weapon::Weapon(std::string type) : type(type)
{
	return ;
}

Weapon::Weapon( void )
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}
