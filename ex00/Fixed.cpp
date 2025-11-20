/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:58:49 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/19 17:24:01 by pauladretta      ###   ########.fr       */
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

// a copy assignment operator overload
Fixed& Fixed::operator= (const Fixed &og)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &og) // adress = address
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
