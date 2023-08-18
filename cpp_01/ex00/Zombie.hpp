
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
	private:

		std::string	name;
		Zombie( std::string name );

	public:

		void	announce( void );
		void	randomChump( std::string name);
		Zombie* newZombie( std::string name );
		Zombie( void );
		~Zombie();
};

# endif // ZOMBIE_H