// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Brain.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string> // needed for std::string

class Brain
{

	protected:

		std::string ideas[100];
	
	public:

		Brain();
		Brain(const Brain& src);
		~Brain();
		Brain& operator=(const Brain& rhs);

};

#endif // BRAIN_HPP

// -------------------------------------------------------------------------- //
