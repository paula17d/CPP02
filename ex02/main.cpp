/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:40:12 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/22 16:10:36 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a(3);
    Fixed b(2);

    if (a > b) 
        std::cout << "a bigger than b" << std::endl;
    if (a < b)
        std::cout << "a smaller than b" << std::endl;
    if (a >= b)
        std::cout << "a bigger than/equal to b" << std::endl;
    if (a <= b)
        std::cout << "a smaller than/equal to b" << std::endl;
    if (a == b)
        std::cout << "a equal to b" << std::endl;
    if (a != b)
        std::cout << "a does not equal b" << std::endl;
        
    return 0;
}

// subject main
// int main( void ) 
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
    
//     return 0;
// }
