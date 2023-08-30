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
#include <iostream>

class Fixed
{

	public:
	
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void  ) const;
		int		toInt( void  ) const;	

		Fixed& operator = ( const Fixed& rhs );

		// comparison operators
		bool operator >  ( const Fixed& rhs ) const;
		bool operator <  ( const Fixed& rhs ) const;
		bool operator <= ( const Fixed& rhs ) const;
		bool operator >= ( const Fixed& rhs ) const;
		bool operator == ( const Fixed& rhs ) const;
		bool operator != ( const Fixed& rhs ) const;

		// arithmetic operators
		Fixed operator + ( const Fixed& rhs ) const;
		Fixed operator - ( const Fixed& rhs ) const;
		Fixed operator * ( const Fixed& rhs ) const;
		Fixed operator / ( const Fixed& rhs ) const;

		// increment operators
			// ++obj
			// obj++
			// --obj
			// obj--

		// static member functions
		static Fixed& min ( Fixed& obj_l, Fixed& obj_r);
		static const Fixed& min ( const Fixed& obj_l, const Fixed& obj_r);
		static Fixed& max ( Fixed& obj_l, Fixed& obj_r);
		static const Fixed& max ( const Fixed& obj_l, const Fixed& obj_r);

		Fixed();
		Fixed( int const number );
		Fixed( float const number );
		Fixed( const Fixed& src );
		~Fixed();

	private:

		int              	_fixed_point_number;
		static const int 	_fractional_bits;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP

// -------------------------------------------------------------------------- //
