// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Fixed.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> // needed for std::ostream

class Fixed
{

	public:
	
		int 	getRawBits (void) const;
		void	setRawBits (int const raw );
		float	toFloat    (void) const;
		int		toInt      (void ) const;	

		Fixed& operator=( const Fixed& rhs );

		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		Fixed(const Fixed& src);
		~Fixed();

	private:

		int              	_fixed_point_number;
		static const int 	_fractional_bits;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP

// -------------------------------------------------------------------------- //
