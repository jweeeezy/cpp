// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Ice.hpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria
{

	public:


		virtual AMateria* clone() const;
	
		virtual void use(ICharacter& target);

		Ice();
		Ice(const Ice& src);
		~Ice();
		Ice& operator=(const Ice& rhs);

};

#endif

// -------------------------------------------------------------------------- //
