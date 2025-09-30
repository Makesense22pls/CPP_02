#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) : value(other.value){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->value = other.getRawBits();
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
};