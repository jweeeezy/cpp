// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Cure.hpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp" // needed for AMateria class, ICharacter interface

class Cure : public AMateria
{

	public:

		AMateria* clone() const;
	
		void use(ICharacter& target);

		Cure();
		Cure(const Cure& src);
		~Cure();
		Cure& operator=(const Cure& rhs);

};

#endif // CURE_HPP

// -------------------------------------------------------------------------- //
