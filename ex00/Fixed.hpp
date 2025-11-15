/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:53:31 by pdrettas          #+#    #+#             */
/*   Updated: 2025/11/15 16:11:58 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int _fixedPointNum;
        static const int _fractionalBits = 8; // value will always be the integer literal 8
    
    public:
        Fixed(); // default constructor that initializes the fixed-point num value to 0.
        Fixed(Fixed &og); // copy constructor
        Fixed& operator= (Fixed &og); // a copy assignment operator overload
        ~Fixed(); // deconstructor
        int getRawBits(void) const; // returns raw value of the fixed-point value
        void setRawBits(int const raw); // sets the raw value of the fixed-point number
};

#endif