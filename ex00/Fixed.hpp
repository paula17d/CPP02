/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:53:31 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/15 19:34:52 by pdrettas         ###   ########.fr       */
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
        Fixed(Fixed &og);
        Fixed& operator= (Fixed &og);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
