/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 16:33:22 by opelser          ###   ########.fr       */
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
	:	ClapTrap("ScavTrap")
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
		std::cout << this->_name << " has entered Gate keeper mode" << std::endl;
	this->_energyPoints--;
}
