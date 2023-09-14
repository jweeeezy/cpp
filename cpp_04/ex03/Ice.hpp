// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Ice.hpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp" // needed for AMateria class, ICharacter interface

class Ice : public AMateria
{

	public:
		
		AMateria* clone() const;
	
		void use(ICharacter& target);

		Ice();
		Ice(const Ice& src);
		~Ice();
		Ice& operator=(const Ice& rhs);

};

#endif

// -------------------------------------------------------------------------- //
