#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed{
	private:
			int value;
			int static const f_bits = 8;

	public:
			Fixed();
			~Fixed();
			Fixed(const Fixed& other);
			Fixed &operator=(const Fixed& other);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
};




#endif