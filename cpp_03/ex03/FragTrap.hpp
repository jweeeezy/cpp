// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  FragTrap.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp" // needed for ClapTrap class, std::string

class FragTrap : virtual public ClapTrap
{

	public:
		
		void highFiveGuys(void);

		FragTrap(std::string name);
		FragTrap(void);
		FragTrap(const FragTrap& src);
		~FragTrap();
		FragTrap& operator=(const FragTrap& rhs);

};

#endif // FRAGTRAP_HPP

// -------------------------------------------------------------------------- //
