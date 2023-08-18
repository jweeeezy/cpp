
#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int N, std::string name )
{
	Zombie*	ptr;

	ptr = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		ptr[i].name = name;
	}
	return(ptr);
}