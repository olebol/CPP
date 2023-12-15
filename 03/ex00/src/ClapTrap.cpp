/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/15 16:38:05 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

ClapTrap::ClapTrap(void)
	:	_name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	:	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// ************************************************************************** //
//                              Member functions                              //
// ************************************************************************** //

bool	ClapTrap::canDoAction(const std::string &action) const
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has lost all HP and can't " << action << "!" << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't " << action << "!" << std::endl;
		return (false);
	}

	return (true);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << " for " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't take any more damage!" << std::endl;
	}
	else if (this->_hitPoints - (int) amount <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << this->_hitPoints << " points of damage and becomes immobilized!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->canDoAction("repair") == false)
		return ;
	if (this->_hitPoints + amount > 10)
	{
		std::cout << "ClapTrap " << this->_name << " repairs " << 10 - this->_hitPoints << " HP and can't repair any more!" << std::endl;
		this->_hitPoints = 10;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " repairs " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
}
