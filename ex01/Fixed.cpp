/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:06:39 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/12 20:59:48 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointValue = raw;
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
