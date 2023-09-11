// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  WrongAnimal.hpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string> // needed for string

class WrongAnimal
{

	protected:

		std::string type;

	public:

		std::string getType() const;
		
		void makeSound() const;

		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& rhs);

};

#endif

// -------------------------------------------------------------------------- //
