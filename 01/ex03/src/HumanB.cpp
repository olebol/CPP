/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:58:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 19:45:12 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

HumanB::HumanB(void)
	:	_name(), _weapon(nullptr)
{
	std::cout << C_LBLUE << C_BOLD << "Constructing a human..." << C_RESET << std::endl;
}

HumanB::HumanB(const std::string &name)
	:	_name(name), _weapon(nullptr)
{
	std::cout << C_LBLUE << C_BOLD << "Constructing " \
				<< this->_name << "..." << C_RESET << std::endl;
}

HumanB::HumanB(const HumanB &copy)
	:	_name(copy._name), _weapon(copy._weapon)
{
	std::cout << C_LBLUE << C_BOLD << "Constructing a copy of " \
				<< this->_name << "..." << C_RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << C_LRED << C_BOLD << "Destructing " \
				 << this->_name << "..." << C_RESET << std::endl;
}

// ************************************************************************** //
//                                   Methods                                  //
// ************************************************************************** //

void		HumanB::attack(void)
{
	if (_weapon != NULL)
	{
		std::cout << this->_name << " attacks with their " \
					<< this->_weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	}
}

void		HumanB::setWeapon(Weapon &newWeapon)
{
	this->_weapon = &newWeapon;
}
