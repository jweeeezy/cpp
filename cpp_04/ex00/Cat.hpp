// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Cat.hpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp" // needed for Animal class

class Cat : public Animal
{

	public:

		void makeSound() const;

		Cat();
		Cat(const Cat& src);
		~Cat();
		Cat& operator=(const Cat& rhs);

};

#endif // CAT_HPP

// -------------------------------------------------------------------------- //
