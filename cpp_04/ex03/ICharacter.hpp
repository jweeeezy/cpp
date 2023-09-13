// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ICharacter.hpp                                                      //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>       // needed for std::string
#include "AMateria.hpp" // needed for AMateria class

class ICharacter
{

	public:
		
		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP

// -------------------------------------------------------------------------- //
