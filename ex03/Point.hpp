/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:26:30 by pauladretta       #+#    #+#             */
/*   Updated: 2025/11/26 15:56:39 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y; 
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &og);
        Point& operator=(const Point &og);
        ~Point();
        const Fixed &getX() const;
        const Fixed &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif