/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:58:49 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/22 16:48:34 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor that initializes the fixed-point num value to 0
Fixed::Fixed() : 
    _fixedPointNum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &og)
{
    std::cout << "Copy constructor called" << std::endl;
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
    std::cout << "Int constructor called" << std::endl;
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
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointNum = roundf(num * (1 << this->_fractionalBits));
}

// a copy assignment operator overload
Fixed& Fixed::operator= (const Fixed &og)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &og)
        this->_fixedPointNum = og.getRawBits();
    return *this;
}

// deconstructor
Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl;
}

// returns the raw value of the fixed-point value
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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
