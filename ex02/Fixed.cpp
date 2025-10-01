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
	*this = other;
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
};

float Fixed::toFloat(void) const {
	return (float)(this->value) / (1 << f_bits);
};

int Fixed::toInt(void) const {
	return (this->value >> f_bits);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}


//OPERATORRRRRR
bool Fixed::operator>(const Fixed &other) const {
	return(this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const {
	return(this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return(this->value >= other.value);
}
bool Fixed::operator<=(const Fixed &other) const {
	return(this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other)const {
	return(this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other)const {
	return(this->value != other.value);
}


Fixed Fixed::operator+(const Fixed &other)const {
	Fixed result;
	result.value = this->value + other.value;
	return (result);
}
Fixed Fixed::operator-(const Fixed &other)const {
	Fixed result;
	result.value = this->value - other.value;
	return (result);
}
Fixed Fixed::operator*(const Fixed &other)const {
	Fixed result;
	result.value = (this->value * other.value) >> f_bits;
	return (result);
}
Fixed Fixed::operator/(const Fixed &other) const{
	Fixed result;
	result.value = (this->value << f_bits) / other.value;
	return (result);
}

Fixed &Fixed::operator++(){
	this->value++;
	return (*this);
}

Fixed &Fixed::operator--(){
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	this->value++;
	return (temp);
}
Fixed Fixed::operator--(int){
	Fixed temp = *this;
	this->value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return a;
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return a;
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return (b);
}
