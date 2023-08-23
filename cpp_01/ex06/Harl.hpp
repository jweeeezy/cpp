
#ifndef HARL_H
# define HARL_H

#include <iostream>	// needed for std::cout, std::endl

#define MESSAGE_DEBUG 	"USB Flash drive <SneakyStick> and your machine are a match!"
#define MESSAGE_INFO 	"USB Flash drive <SneakyStick> would like to share data..."
#define MESSAGE_WARNING "USB Flash drive <SneakyStick> has been left on read." \
						" Data loss is a matter of time..."
#define MESSAGE_ERROR 	"USB Flash drive <SneakyStick> has lost the connection " \
						"and all your shared data because of Early Ejection!"
#define MESSAGE_DEFAULT "*just random swipes... one to the left, one to the right!*"

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

		typedef void (Harl::*harl_fptr)();

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
