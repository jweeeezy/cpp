// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  IMateriaSource.hpp                                                  //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp" // needed for AMateria class, std::string

class IMateriaSource
{
	
	public:
		
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif // IMATERIASOURCE_HPP

// -------------------------------------------------------------------------- //
