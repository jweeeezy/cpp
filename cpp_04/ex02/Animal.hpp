// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Animal.hpp                                                          //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string> // needed for string

class Animal
{
	protected:

		std::string type;
	
	public:

		std::string getType() const;

		virtual void makeSound() const = 0;
		
		Animal(std::string t);
		Animal();
		Animal(const Animal& src);
		virtual ~Animal();
		Animal& operator=(const Animal& rhs);

};

#endif // ANIMAL_HPP

// -------------------------------------------------------------------------- //
