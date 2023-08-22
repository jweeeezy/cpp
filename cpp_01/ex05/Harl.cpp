
#include "Harl.hpp"

Harl::function_map Harl::_function_map[4] = 
{
    {"DEBUG", &Harl::debug},
	{"INFO", &Harl::info},
	{"WARNING", &Harl::warning},
	{"ERROR", &Harl::error}
};

void	Harl::complain( std::string level )
{
	for (size_t i = 0; i < 4; ++i)
	{
		if (level == _function_map[i].level)
		{
			(this->*_function_map[i].func)();
			return ;
		}
	}
	return ;
}

void	Harl::debug( void )
{
	std::cout << MESSAGE_DEBUG << std::endl;
	return ;
}

void	Harl::info( void )
{
	std::cout << MESSAGE_INFO << std::endl;
	return ;
}


void	Harl::warning( void )
{
	std::cout << MESSAGE_WARNING << std::endl;
	return ;
}

void	Harl::error( void )
{
	std::cout << MESSAGE_ERROR << std::endl;
	return ;
}

Harl::Harl( void )
{
	this->_function_map[0].level = "DEBUG";
	this->_function_map[0].func = &Harl::debug;
	return ;
}

Harl::~Harl()
{
	return ;
}

/* ************************************************************************** */
