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

#ifndef BRAIN_SIZE
# define BRAIN_SIZE 100
#endif // BRAIN_SIZE

class Brain
{

	private:

		std::string ideas[BRAIN_SIZE];
	
	public:

		std::string getIdea(int pos);

		void setIdea(std::string idea, int pos);

		Brain();
		Brain(const Brain& src);
		~Brain();
		Brain& operator=(const Brain& rhs);

};

#endif // BRAIN_HPP

// -------------------------------------------------------------------------- //
