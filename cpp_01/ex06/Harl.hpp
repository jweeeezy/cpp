
#ifndef HARL_H
# define HARL_H

#include <iostream>	// needed for std::cout, std::endl

// @todo think about some funny messages
#define MESSAGE_DEBUG	"debug!"
#define MESSAGE_INFO	"info!"
#define MESSAGE_WARNING	"warning!"
#define MESSAGE_ERROR	"error!"
#define MESSAGE_DEFAULT "*white noise*"

#define CASE_DEBUG		0
#define CASE_INFO		1
#define CASE_WARNING	2
#define CASE_ERROR		3

class Harl
{
	private:

		void		debug	( void );
		void		info	( void );
		void		warning	( void );
		void		error	( void );

		typedef void (Harl::*harl_fptr)();	// @todo ask chatgpt about this again

		typedef struct	function_map
		{
			std::string	level;
			harl_fptr	func;
		}				t_func_map;

		static function_map	_function_map[4];

	public:

		void		complain	( std::string level );

		Harl( void );
		~Harl();
};

#endif //	HARL_H

/* ************************************************************************** */
