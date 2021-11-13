/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:06:39 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/13 17:12:59 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	setRawBits(0);
}

Fixed::Fixed( const Fixed &fixed )
{
	*this = fixed;
}

Fixed::Fixed( const int value )
{
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed( const float value )
{
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits( int const value )
{
	_fixedPointValue = value;
}

float Fixed::toFloat( void ) const
{
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream &operator<<( std::ostream &ostream, const Fixed &fixed )
{
	ostream << fixed.toFloat();
	return (ostream);
}

Fixed &Fixed::operator=( const Fixed &other )
{
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

bool Fixed::operator>( const Fixed &other ) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<( const Fixed &other ) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=( const Fixed &other ) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=( const Fixed &other ) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==( const Fixed &other ) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=( const Fixed &other ) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+( const Fixed &other ) const
{
	return (Fixed(this->getRawBits() + other.getRawBits()));
}

Fixed Fixed::operator-( const Fixed &other ) const
{
	return (Fixed(this->getRawBits() - other.getRawBits()));
}

Fixed Fixed::operator*( const Fixed &other ) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/( const Fixed &other ) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++( void )
{
	_fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	_fixedPointValue += 1;
	return (tmp);
}

Fixed &Fixed::operator--( void )
{
	_fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	_fixedPointValue -= 1;
	return (tmp);
}

Fixed &Fixed::min( Fixed &f1, Fixed &f2 )
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max( Fixed &f1, Fixed &f2 )
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	return (f1 > f2 ? f1 : f2);
}
