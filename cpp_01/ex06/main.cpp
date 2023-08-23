#include "Harl.hpp"

#include <iostream>	// needed for std::cerr, std::endl
#include <cstdlib>	// needed for MACROS

int	main(int argc, char **argv)
{
	Harl	h;

	if (argc != 2)
	{
		std::cerr << "error: bad arguments!" << std::endl;
		return (EXIT_FAILURE);
	}
	h.complain(argv[1]);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
