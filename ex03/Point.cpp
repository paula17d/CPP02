/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:27:29 by pauladretta       #+#    #+#             */
/*   Updated: 2025/11/26 13:28:00 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point &og) : _x(og.getX()), _y(og.getY())
{}

// note: constant references cannot be changed (_x, _y)
Point& Point::operator=(const Point &og)
{
    (void) og;
    return (*this);
}

Point::~Point()
{}

const Fixed &Point::getX() const
{
    return this->_x;
}

const Fixed &Point::getY() const
{
    return this->_y;
}
