#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int n) : value(n << f_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value(roundf(f * (1 << f_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->value = other.value;
	return (*this);
};

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
};

int Fixed::getRawBits (void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return(value);
};

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return (float)(this->value) / (1 << f_bits);
}

int Fixed::toInt(void) const {
	return (this->value >> f_bits);
}

std::ostream &operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}