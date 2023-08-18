
#include <string>

class Zombie
{

	private:

		std::string	name;
		Zombie( std::string name );

	public:

		Zombie*	zombieHorde( int N, std::string name);
		Zombie* newZombie( std::string name );
		void	announce( void );
		Zombie(/* args */);
		~Zombie();

};
