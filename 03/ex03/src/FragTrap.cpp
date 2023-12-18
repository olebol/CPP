/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 18:32:52 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

FragTrap::FragTrap(void)
	:	ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << GREEN << "Default FragTrap constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	:	ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << GREEN << "Parameterized FragTrap constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << GREEN << "FragTrap Copy constructor called" << RESET << std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << GREEN << "FragTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                              Member functions                              //
// ************************************************************************** //

void	FragTrap::highFiveGuys(void)
{

	if (this->canDoAction("high five") == false)
		return ;
	else
	{
		std::cout << "FragTrap " << this->_name << ": \"High five guys! ... Guys?\"" << std::endl;
		this->_energyPoints--;
		// ego--;
	}
}

void	FragTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	std::cout << "FragTrap " << this->_name << " attacks " << target;
	std::cout << " with explosions for " << this->_attackDamage << " points of damage!" << std::endl;

	this->_energyPoints--;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't take any more damage!" << std::endl;
	}
	else if (this->_hitPoints - (int) amount <= 0)
	{
		std::cout << "FragTrap " << this->_name << " takes " << this->_hitPoints << " points of damage and becomes immobilized!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->canDoAction("repair") == false)
		return ;
	if (this->_hitPoints + (int) amount > this->_maxHitPoints)
	{
		std::cout << "FragTrap " << this->_name << " repairs " << this->_maxHitPoints - this->_hitPoints << " HP and can't repair any more!" << std::endl;
		this->_hitPoints = 10;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " repairs " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
}
