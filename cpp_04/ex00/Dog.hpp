// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Dog.hpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp" // needed for Animal class

class Dog : virtual public Animal
{

	public:

		void MakeSound() const;

		Dog();
		Dog(const Dog& src);
		~Dog();
		Dog& operator=(const Dog& rhs);

};

#endif // DOG_HPP

// -------------------------------------------------------------------------- //
