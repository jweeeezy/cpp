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
#include "Brain.hpp"  // needed for Brain class

class Dog : public Animal
{
	private:

		Brain* brain;

	public:

		std::string getIdea(int pos);
		void        setIdea(std::string idea, int pos);

		virtual void makeSound() const;

		Dog();
		Dog(const Dog& src);
		~Dog();
		Dog& operator=(const Dog& rhs);

};

#endif // DOG_HPP

// -------------------------------------------------------------------------- //
