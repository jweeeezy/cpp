
#include <string>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon
{
	private:
		std::string	type;
	public:

		const std::string& getType( void ) const;
		void	setType( std::string );

		Weapon(std::string type);
		Weapon( void );
		~Weapon();
};

#endif // WEAPON_H
