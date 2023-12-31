// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ClapTrap.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string> // needed for std::string

class ClapTrap
{
	
	protected: // so inheritance works!

		std::string name;
		short int   hit_points;
		short int   energy_points;
		short int   attack_damage;

	public:

		std::string getName(void) const;
		short int   getHitPoints(void) const;
		short int   getEnergyPoints(void) const;
		short int   getAttackDamage(void) const;

		void attack(const std::string& target);
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount);

		ClapTrap(std::string name);
		ClapTrap();
		ClapTrap(const ClapTrap& src);
		~ClapTrap();
		ClapTrap& operator = (const ClapTrap& rhs);

};

#endif // CLAPTRAP_HPP

// -------------------------------------------------------------------------- //
