// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AMateria.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>         // needed for std::string
#include "ICharacter.hpp" // needed for ICharacter interface

class AMateria
{
	protected:




	public:

		AMateria(std::string const & type);



		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria();
		AMateria(const AMateria& src);
		~AMateria(); // @note virtual?
		AMateria& operator=(const AMateria& rhs);

};

#endif // AMATERIA_HPP

// ------------------------------------------------------------------------- //
