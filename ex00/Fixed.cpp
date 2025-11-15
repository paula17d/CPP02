/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:58:49 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/15 16:13:19 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : 
    _fixedPointNum(0)
{}

Fixed::Fixed(Fixed &og)
{
    this->_fixedPointNum = og._fixedPointNum; // TODO: get ft?
}

// TODO: operator ft

Fixed::~Fixed()
{}

// TODO: getRawBits ft


// TODO: setRawBits ft
