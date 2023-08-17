
#include "class.Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout	<< this->name
				<< ": "
				<< "BraiiiiiiinnnzzzZ..."
				<< std::endl;
	return ;
}

Zombie*	Zombie::newZombie( std::string name )
{
	return (new Zombie(name));
}

void	Zombie::randomChump( std::string name )
{
	Zombie	chump(name);
	chump.announce();
	return ;
}

Zombie::Zombie( std::string name ) : name(name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout	<< "Destructor of "
				<< this->name
				<< " called"
				<< std::endl;
	return ;
}