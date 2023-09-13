// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  WrongCat.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp" // needed for WrongAnimal class

class WrongCat : public WrongAnimal
{

	public:

		void makeSound() const;

		WrongCat();
		WrongCat(const WrongCat& src);
		~WrongCat();
		WrongCat& operator=(const WrongCat& rhs);

};

#endif

// -------------------------------------------------------------------------- //
