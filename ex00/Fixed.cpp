/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:58:49 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/15 19:34:42 by pdrettas         ###   ########.fr       */
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
Fixed::Fixed(Fixed &og)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointNum = og.getRawBits();
}

// a copy assignment operator overload
Fixed& Fixed::operator= (Fixed &og)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
