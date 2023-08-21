
#ifndef HARL_H
# define HARL_H

#include <iostream>	// needed for std::cout, std::endl

#define MESSAGE_DEBUG	"debug!"
#define MESSAGE_INFO	"info!"
#define MESSAGE_WARNING	"warning!"
#define MESSAGE_ERROR	"error!"

class Harl
{
	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:

		void	complain( std::string level );

		Harl( void );
		~Harl();
};

#endif //	HARL_H

/* ************************************************************************** */