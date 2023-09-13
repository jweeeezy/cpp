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

#include <string> // needed for std::string

class ICharacter; // "forward declaration" - only reference is used

class AMateria
{
	protected:
		
		std::string const type;

	public:

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		
		virtual void use(ICharacter& target);

		AMateria(std::string const & type);
		AMateria();
		AMateria(const AMateria& src);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& rhs);

};

#endif // AMATERIA_HPP

// ------------------------------------------------------------------------- //
