/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 18:09:04 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

ClapTrap::ClapTrap(void)
	:	_name("Default"), _hitPoints(10), _maxHitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "Default ClapTrap constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	:	_name(name), _hitPoints(10), _maxHitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "Parameterized ClapTrap constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GREEN << "ClapTrap Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << GREEN << "ClapTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_maxHitPoints = rhs._maxHitPoints;
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
	std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                              Member functions                              //
// ************************************************************************** //

bool	ClapTrap::canDoAction(const std::string &action) const
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " has lost all HP and can't " << action << "!" << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " is out of energy and can't " << action << "!" << std::endl;
		return (false);
	}

	return (true);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	std::cout << "ClapTrap" << this->_name << " attacks " << target;
	std::cout << " for " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap" << this->_name << " can't take any more damage!" << std::endl;
	}
	else if (this->_hitPoints - (int) amount <= 0)
	{
		std::cout << "ClapTrap" << this->_name << " takes " << this->_hitPoints << " points of damage and becomes immobilized!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap" << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->canDoAction("repair") == false)
		return ;
	if (this->_hitPoints + (int) amount > this->_maxHitPoints)
	{
		std::cout << "ClapTrap" << this->_name << " repairs " << this->_maxHitPoints - this->_hitPoints << " HP and can't repair any more!" << std::endl;
		this->_hitPoints = 10;
	}
	else
	{
		std::cout << "ClapTrap" << this->_name << " repairs " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
}
