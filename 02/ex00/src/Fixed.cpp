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

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &rhs)
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



// ************************************************************************** //
//                                   Getters                                  //
// ************************************************************************** //



// ************************************************************************** //
//                               Private Methods                              //
// ************************************************************************** //



// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
