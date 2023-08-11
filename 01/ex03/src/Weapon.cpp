/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:28:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 22:07:29 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Implement a Weapon class that has:
// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as parameter.

#include "Weapon.hpp"
#include <iostream>

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Weapon::Weapon(void)
	: _type()
{
	std::cout << C_LBLUE << C_BOLD << "Constructing a weapon..." << C_RESET << std::endl;
}

Weapon::Weapon(const std::string &type)
	:	_type(type)
{
	std::cout << C_LBLUE << C_BOLD << "Constructing " \
				<< _type << "..." << C_RESET << std::endl;
}

Weapon::Weapon(const Weapon &copy)
	:	_type(copy._type)
{
	std::cout << C_LBLUE << C_BOLD << "Constructing a copy of " \
				<< this->_type << "..." << C_RESET << std::endl;
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

Weapon::~Weapon(void)
{
	std::cout << C_LRED << C_BOLD << "Destructing " \
				<< this->_type << "..." << C_RESET << std::endl;
}

// ************************************************************************** //
//                                   Getters                                  //
// ************************************************************************** //

const std::string &		Weapon::getType(void) const
{
	return (this->_type);
}

// ************************************************************************** //
//                                   Setters                                  //
// ************************************************************************** //

void					Weapon::setType(const std::string &type)
{
	this->_type = type;
}
