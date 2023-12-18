/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 16:46:39 by opelser          ###   ########.fr       */
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
	:	ClapTrap("FragTrap Default")
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
		std::cout << this->_name << ": \"High five guys! ... Guys?\"" << std::endl;
		this->_energyPoints--;
		// ego--;
	}
}
