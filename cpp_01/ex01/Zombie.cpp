
#include "Zombie.hpp"
#include <iostream>		// needed for std::cout, std::endl

#define COLOR_LOG YELLOW
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void	Zombie::announce( void )
{
	std::cout	<< this->name
				<< ": "
				<< "BraiiiiiiinnnzzzZ..."
				<< std::endl;
	return ;
}

Zombie::Zombie( void )
{
	std::cout	<< COLOR_LOG
				<< "Default constructor called"
				<< RESET
				<< std::endl;
	return ;
}

Zombie::Zombie( std::string name ) : name(name)
{
	std::cout	<< COLOR_LOG
				<< "Constructor of "
				<< name
				<< " called"
				<< RESET
				<< std::endl;
	return ;
}

Zombie*	Zombie::newZombie( std::string name )
{
	return (new Zombie(name));
}

Zombie::~Zombie()
{
	if (this->name.empty())
	{
		std::cout	<< COLOR_LOG
					<< "Destructor called"
					<< RESET
					<< std::endl;
	}
	else
	{
		std::cout	<< COLOR_LOG
					<< "Destructor of "
					<< this->name
					<< " called"
					<< RESET
					<< std::endl;
	}
	return ;
}