/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 18:33:52 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

DiamondTrap::DiamondTrap(void)
	:	ScavTrap("Default"), FragTrap("Default"), _name("Default")
{
	std::cout << GREEN << "Default DiamondTrap constructor called" << RESET << std::endl;

	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name)
	:	ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << GREEN << "Parameterized DiamondTrap constructor called" << RESET << std::endl;

	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << GREEN << "DiamondTrap Copy constructor called" << RESET << std::endl;

	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << GREEN << "DiamondTrap Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs._name;
	}

	FragTrap::operator=(rhs);
	ScavTrap::operator=(rhs);

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                              Member functions                              //
// ************************************************************************** //

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}


void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "DiamondTrap " << this->_name << " can't take any more damage!" << std::endl;
	}
	else if (this->_hitPoints - (int) amount <= 0)
	{
		std::cout << "DiamondTrap " << this->_name << " takes " << this->_hitPoints << " points of damage and becomes immobilized!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "DiamondTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->canDoAction("repair") == false)
		return ;
	if (this->_hitPoints + (int) amount > this->_maxHitPoints)
	{
		std::cout << "DiamondTrap " << this->_name << " repairs " << this->_maxHitPoints - this->_hitPoints << " HP and can't repair any more!" << std::endl;
		this->_hitPoints = 10;
	}
	else
	{
		std::cout << "DiamondTrap " << this->_name << " repairs " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
}

