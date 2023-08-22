
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

		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );

		typedef void (Harl::*harl_fptr)();

		typedef struct	function_map
		{
			std::string	level;
			harl_fptr	func;
		}				t_func_map;
		
		static function_map	_function_map[4];

	public:

		void		complain( std::string level );
		
		
		
		Harl( void );
		~Harl();
};

#endif //	HARL_H

/* ************************************************************************** */
