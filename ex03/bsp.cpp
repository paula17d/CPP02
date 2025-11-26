/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:54:39 by pauladretta       #+#    #+#             */
/*   Updated: 2025/11/26 16:28:35 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Triangle Corner Points: a, b, c
Point inside or outside triangle: point

Formula to calculate area
A = (xA​(yB​−yC​)+xB​(yC​−yA​)+xC​(yA​−yB​)) / 2

Areas of the sub-triangles with point P
A1 ​= Area(P,B,C)
A2 ​= Area(A,P,C)
A3 ​= Area(A,B,P)
*/
static float area(Point const a, Point const b, Point const c)
{
    return ( (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
           + (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
           + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) ) / 2.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A  = std::abs(area(a, b, c));
    float A1 = std::abs(area(point, b, c));
    float A2 = std::abs(area(a, point, c));
    float A3 = std::abs(area(a, b, point));

    // conditions for P being inside the triangle
    if ((A1 > 0 && A2 > 0 && A3 > 0) && (A == A1 + A2 + A3))
        return true;
    else   
        return false; 
}
