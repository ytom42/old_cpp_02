/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:46:28 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/11/13 12:35:04 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &fixed );
		~Fixed( void );
		Fixed &operator=( const Fixed &other );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif