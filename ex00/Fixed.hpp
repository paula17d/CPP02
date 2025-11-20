/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:53:31 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/19 16:50:27 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedPointNum;
        static const int _fractionalBits = 8; // value will always be the integer literal 8
    
    public:
        Fixed();
        Fixed(const Fixed &og);
        Fixed& operator= (const Fixed &og);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
