/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:40:12 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/26 16:21:42 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

std::string pointLocation(bool status)
{
    if (status == 1)
        return "\033[32mPoint is inside of triangle\033[0m";
    else
        return "\033[31mPoint is outside of triangle\033[0m";
}

int main ()
{
    // triangle
    Point a(1.38f, 2.79f);
    Point b(0.8f, 4.79f);
    Point c(3.2f, 6.79f);
    
    // inside
    Point p1(1.90f, 4.45f);
    Point p2(1.80f, 4.30f); 
    Point p3(1.81f, 4.39f); 
    Point p4(1.93f, 4.99f); 
    // outside
    Point p5(2.45f, 3.45f); 
    Point p6(0.50f, 5.00f);
    Point p7(2.29f, 4.79f); // on edge
    Point p8(1.09f, 3.79f); // on edge

    Point points[] = {p1, p2, p3, p4, p5, p6, p7, p8};

    for (int i = 0; i < 8; i++)
        std::cout << "p" << i+1 << " = " << pointLocation(bsp(a, b, c, points[i])) << std::endl;

    return 0;
}
