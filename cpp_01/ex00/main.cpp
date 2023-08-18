
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie_class;
	Zombie	*ptr;

	ptr = zombie_class.newZombie("Alfred");
	zombie_class.randomChump("Brian");
	ptr->announce();
	delete ptr;
	return (EXIT_SUCCESS);
}