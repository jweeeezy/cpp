#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
private:

	std::string	name;
	Weapon*		weapon;

public:

	void	attack( void );
	void	setWeapon(Weapon& weapon);
	HumanB(const std::string& name);
	~HumanB();

};

#endif // HUMANB_H
