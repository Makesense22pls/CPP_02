#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <math.h>

class Fixed{
	private:
			int value;
			int static const f_bits = 8;

	public:
			Fixed();
			Fixed(const int);
			Fixed(const float);
			~Fixed();
			Fixed(const Fixed& other);
			Fixed &operator=(const Fixed& other);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			float toFloat(void) const;
			int toInt(void) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

#endif