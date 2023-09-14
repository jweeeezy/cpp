// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  MateriaSource.hpp                                                   //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp" // needed for IMateriaSource interface

class MateriaSource : public IMateriaSource
{
	protected:
		
		AMateria* storage[4];

	public:

		void showStorage();

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

		MateriaSource();
		MateriaSource(const MateriaSource& src);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& rhs);

};

#endif // MATERIASOURCE_HPP

// -------------------------------------------------------------------------- //
