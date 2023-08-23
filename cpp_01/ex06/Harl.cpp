
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
	bool is_filtered = false;

	for (size_t i = 0; i < 4; ++i)
	{
		if (level == _function_map[i].level)
		{
			is_filtered = true;
			switch (i)
			{
				case 0:
					this->debug();
				case 1:
					this->info();
				case 2:
					this->warning();
				case 3:
					this->error();
			}
		}
	}

	if (is_filtered == false)
	{
		std::cout << "*white noise*" << std::endl;
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
	return ;
}

Harl::~Harl()
{
	return ;
}

/* ************************************************************************** */
