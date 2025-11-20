/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:53:31 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/20 19:32:40 by pauladretta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPointNum;
        static const int _fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &og);
        Fixed(int const num);
        Fixed(float const num);
        Fixed& operator=(const Fixed &og);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

void operator<<(std::ostream &out_stream, Fixed const &fixed);
void operator<<(Fixed const& p, int z);
Fixed operator>>(Fixed const& p, int z);

#endif
