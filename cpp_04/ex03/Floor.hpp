// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Floor.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp" // needed for AMateria class

#define FLOOR_SIZE 6
#define EMPTY NULL

class Floor
{
	
	protected:

		AMateria* arr[FLOOR_SIZE];

	public:

		void add(AMateria *drop);
		void clean();

		void print() const;

		Floor();
		Floor(const Floor& src);
		~Floor();
		Floor& operator=(const Floor& rhs);

};

#endif // FLOOR_HPP

// -------------------------------------------------------------------------- //
