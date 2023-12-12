/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:01:13 by opelser           #+#    #+#             */
/*   Updated: 2023/12/12 19:42:04 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include "../include/Fixed.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Point::Point(void)
	: _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y)
	: _x(x), _y(y)
{
	// std::cout << "Float constructor called " << _x << " " << _y << std::endl;
}

Point::Point(const Point &copy)
	: _x(copy._x), _y(copy._y)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Point	&Point::operator=(const Point &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	(void) rhs;

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// ************************************************************************** //
//                                 Getters                                    //
// ************************************************************************** //

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}
