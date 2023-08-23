
#include "Harl.hpp"

static inline void	print_message(const std::string& message)
{
	std::cout << message << std::endl;
}

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
	print_message(MESSAGE_DEBUG);
	return ;
}

void	Harl::info( void )
{
	print_message(MESSAGE_INFO);
	return ;
}

void	Harl::warning( void )
{
	print_message(MESSAGE_WARNING);
	return ;
}

void	Harl::error( void )
{
	print_message(MESSAGE_ERROR);
	return ;
}

Harl::Harl( void )
{
	return ;
}

Harl::~Harl()
{
	return ;
}

/* ************************************************************************** */
