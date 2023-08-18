
#include "Zombie.hpp"

void	Zombie::randomChump( std::string name )
{
	Zombie	chump(name);
	chump.announce();
	return ;
}