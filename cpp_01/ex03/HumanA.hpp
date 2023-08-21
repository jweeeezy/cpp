
#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
private:

	const std::string	name;
	Weapon&				weapon;

public:

	void	attack( void ) const;

	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
};

#endif // HUMANA_H
