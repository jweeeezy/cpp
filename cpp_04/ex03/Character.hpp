// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Character.hpp                                                       //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp" // needed for ICharacter interface, AMateria class,
						  // std::string

class Character : public ICharacter
{
	protected:
		
		std::string const name;

		AMateria*  inventory[4];

	public:

		std::string const & getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria* getItem(int idx);

		void showInventory() const;
		void clearInventory();

		Character(std::string const name);
		Character();
		Character(const Character& src);
		~Character();
		Character& operator=(const Character& rhs);

};

#endif // CHARACTER_HPP

// -------------------------------------------------------------------------- //
