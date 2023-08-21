
#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
private:

	std::string	name;
	Weapon&		weapon;

public:

	void	attack( void );
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
};

#endif // HUMANA_H
