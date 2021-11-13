/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:06:56 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/13 17:13:04 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed( void );

		Fixed &operator=( const Fixed &other );
		bool operator>( const Fixed &other ) const ;
		bool operator<( const Fixed &other ) const ;
		bool operator>=( const Fixed &other ) const ;
		bool operator<=( const Fixed &other ) const ;
		bool operator==( const Fixed &other ) const ;
		bool operator!=( const Fixed &other ) const ;
		Fixed operator+( const Fixed &other ) const ;
		Fixed operator-( const Fixed &other ) const ;
		Fixed operator*( const Fixed &other ) const ;
		Fixed operator/( const Fixed &other ) const ;
		Fixed &operator++( void );
		Fixed operator++( int );
		Fixed &operator--( void );
		Fixed operator--( int );

		static Fixed &min( Fixed &f1, Fixed &f2 );
		static const Fixed &min( const Fixed &f1, const Fixed &f2 );
		static Fixed &max( Fixed &f1, Fixed &f2 );
		static const Fixed &max( const Fixed &f1, const Fixed &f2 );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<( std::ostream &ostream, const Fixed &fixed );

#endif