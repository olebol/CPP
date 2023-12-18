/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:38:39 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

ScavTrap::ScavTrap(void)
	:	ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << GREEN << "Default ScavTrap constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	:	ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << GREEN << "Parameterized ScavTrap constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << GREEN << "ScavTrap Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << GREEN << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                              Member functions                              //
// ************************************************************************** //

void	ScavTrap::guardGate(void)
{

	if (this->canDoAction("guard") == false)
		return ;
	else
		std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode!" << std::endl;
	this->_energyPoints--;
}


void	ScavTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << " in the name of RedBelly for " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't take any more damage!" << std::endl;
	}
	else if (this->_hitPoints - (int) amount <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " takes " << this->_hitPoints << " points of damage and becomes immobilized!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->canDoAction("repair") == false)
		return ;
	if (this->_hitPoints + (int) amount > this->_maxHitPoints)
	{
		std::cout << "ScavTrap " << this->_name << " repairs " << this->_maxHitPoints - this->_hitPoints << " HP and can't repair any more!" << std::endl;
		this->_hitPoints = 10;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " repairs " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
}
