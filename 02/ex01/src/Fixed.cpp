/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:25:01 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 23:35:28 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = value * (1 << this->_fractionalBits);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPointValue = rhs.getRawBits();
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// ************************************************************************** //
//                                   Setters                                  //
// ************************************************************************** //

void	Fixed::setRawBits(const int raw)
{
	this->_fixedPointValue = raw;
}

// ************************************************************************** //
//                                   Getters                                  //
// ************************************************************************** //

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

float	Fixed::toFloat(void) const
{
	return ((float) this->_fixedPointValue / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return ((int) this->_fixedPointValue >> this->_fractionalBits);
}

// ************************************************************************** //
//                                 Functions                                  //
// ************************************************************************** //

std::ostream	&operator<<(std::ostream& os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}
