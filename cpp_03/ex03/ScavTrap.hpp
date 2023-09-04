// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ScavTrap.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp" // needed for ClapTrap class, std::string

class ScavTrap : virtual public ClapTrap
{

	public:
		void attack(const std::string &target);
		void guardGate(void);

		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(const ScavTrap& src); 
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& rhs);

};

#endif // SCAVTRAP_HPP

// -------------------------------------------------------------------------- //
