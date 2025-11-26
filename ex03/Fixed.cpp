/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:58:49 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/23 18:49:20 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor that initializes the fixed-point num value to 0
Fixed::Fixed() : 
    _fixedPointNum(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &og)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointNum = og.getRawBits();
}

/*
A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value
should be initialized to 8, like in exercise 00.
-> bit shifting num left by _fractionalBits (8) is the same as multiplying it by 2 ^_fractionalBits
*/
Fixed::Fixed(int const num)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixedPointNum = num << this->_fractionalBits;
}

/*
A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value
should be initialized to 8, like in exercise 00.
-> bit shifting num left by _fractionalBits (8) is the same as multiplying it by 2 ^_fractionalBits
-> round to nearest integer, so it fits _fixedPointNum
*/
Fixed::Fixed(float const num)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPointNum = roundf(num * (1 << this->_fractionalBits));
}

// a copy assignment operator overload
Fixed& Fixed::operator=(const Fixed &og)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &og)
        this->_fixedPointNum = og.getRawBits();
    return *this;
}

// deconstructor
Fixed::~Fixed()
{
    // std::cout << "Deconstructor called" << std::endl;
}

// returns the raw value of the fixed-point value
int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNum;
}

// sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNum = raw;
}

/*
converts the fixed-point value to a floating-point value
-> bit shifting computes the scale factor (256 if _fractionalBits = 8)
*/
float Fixed::toFloat(void) const
{
    float num = this->_fixedPointNum / (float)(1 << this->_fractionalBits);
    return num;
}

/*
that converts the fixed-point value to an integer value.
-> bit shifting right (therefore dividing) due to not wanting decimals
*/
int Fixed::toInt(void) const
{
    int num = this->_fixedPointNum >> this->_fractionalBits;
    return num;
}

/*
An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter.
*/
std::ostream& operator<<(std::ostream &out_stream, Fixed const &fixed)
{
    out_stream << fixed.toFloat();
    return out_stream;
}

// The 6 comparison operators: >, <, >=, <=, ==, and !=
bool Fixed::operator>(Fixed const &fixed) const
{
    if (this->toFloat() > fixed.toFloat())
        return true;
    else 
        return false;
}

bool Fixed::operator<(Fixed const &fixed) const
{
    if (this->toFloat() < fixed.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator>=(Fixed const &fixed)
{
    if (this->toFloat() >= fixed.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator<=(Fixed const &fixed)
{
    if (this->toFloat() <= fixed.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator==(Fixed const &fixed)
{
    if (this->toFloat() == fixed.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator!=(Fixed const &fixed)
{
    if (this->toFloat() != fixed.toFloat())
        return true;
    else
        return false;
}

// The 4 arithmetic operators: +, -, *, and /
Fixed Fixed::operator+(Fixed const &fixed)
{
    Fixed result(this->toFloat() + fixed.toFloat());
    return result;
}

Fixed Fixed::operator-(Fixed const &fixed)
{
    Fixed result(this->toFloat() - fixed.toFloat());
    return result;
}

Fixed Fixed::operator*(Fixed const &fixed)
{
    Fixed result(this->toFloat() * fixed.toFloat());
    return result;
}

Fixed Fixed::operator/(Fixed const &fixed)
{
    Fixed result(this->toFloat() / fixed.toFloat());
    return result;
}

/*
The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1.
*/
/*
Operator   Syntax  Who is left	    Who is right
Prefix ++a	++a	   a (the object)	none
Postfix a++	a++	   a (the object)	int dummy
Stream std::cout << a	std::cout << a	std::cout	a

So in a++, a is technically “left” because it’s the object 
calling the operator — the (int) is just a marker for postfix.
*/
/*
pre-increment (++a)
- increases the value of a by 1
- then gives/returns the new number
-> increment first, then use new value
*/ 
Fixed &Fixed::operator++(void)
{
    this->_fixedPointNum++;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    this->_fixedPointNum--;
    return *this;
}

/*
post-increment (a++)
- gives the current value of a
- then increase current a by 1
-> use old value first, then increment
*/
Fixed Fixed::operator++(int)
{
    Fixed x = *this;
    this->_fixedPointNum++;
    return x;
}

Fixed Fixed::operator--(int)
{
    Fixed x = *this;
    this->_fixedPointNum--;
    return x;
}

/*
takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one.
*/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b; 
}

/*
takes two references to constant fixed-point numbers 
as parameters, and returns a reference to the smallest one.
*/
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b; 
}

/*
takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one.
*/
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}
