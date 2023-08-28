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

class Fixed
{

	public:

		int 	getRawBits( void );
		void	setRawBits( int const raw );

		Fixed();
		Fixed( const Fixed& src );
		~Fixed();
		Fixed& operator=( const Fixed& rhs );

	private:

		int              	_fixed_point_number;
		static const int 	_fractional_bits;

};

#endif // FIXED_HPP
