
#include "Zombie.hpp"
#include <cstdlib>		// needed for MACROS

int	main(void)
{
	Zombie	zombie_class;
	Zombie*	ptr;
	int		amount;

	amount = 5;
	ptr = zombie_class.zombieHorde(amount, "Chaos Legion");

	for (int i = 0; i < amount; ++i)
	{
		ptr[i].announce();
	}

	delete[] ptr;
	return (EXIT_SUCCESS);
}