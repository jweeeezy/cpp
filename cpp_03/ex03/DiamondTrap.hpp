// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  DiamondTrap.hpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp" // needed for ClapTrap class, std::string
#include "FragTrap.hpp" // needed for FragTrap class
#include "ScavTrap.hpp" // needed for ScavTrap class

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:

		std::string name;

		using ScavTrap::energy_points;
		
		using FragTrap::hit_points;
		using FragTrap::attack_damage;

	public:

		void whoAmI(void);
		using ScavTrap::attack;

		DiamondTrap(std::string name);
		DiamondTrap();
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& rhs);

};

#endif // DIAMONDTRAP_HPP

// -------------------------------------------------------------------------- //
