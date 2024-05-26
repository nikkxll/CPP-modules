/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/26 20:19:01 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	value;
		static const int fractBitsNum;
		static const int fractionMask;
		static const int wholeMask;
		
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float fixedToFloat(void) const;
		int floatToFixed(const float floatValue) const;
		int fixedToInt(void) const;
		int intToFixed(const int intValue) const;
		int fractionPart(void) const;
		int wholePart(void) const;

		bool operator>(const Fixed& rhs);
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator==(const Fixed& rhs);
		bool operator!=(const Fixed& rhs);
		
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);
		
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		const static Fixed& min(const Fixed& a, const Fixed& b);
		const static Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif