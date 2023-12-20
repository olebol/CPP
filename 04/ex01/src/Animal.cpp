/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:39:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Animal::Animal(void)
	:	_type("Animal")
{
	std::cout << GREEN << "Animal: Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << GREEN << "Animal: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << GREEN << "Animal: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return (*this);
}

// ************************************************************************** //
//                           Protected Constructors                           //
// ************************************************************************** //

Animal::Animal(const std::string &type)
	:	_type(type)
{
	std::cout << GREEN << "Animal: Parameterized constructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

Animal::~Animal()
{
	std::cout << RED << "Animal: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                 Getters                                    //
// ************************************************************************** //

const std::string		&Animal::getType(void) const
{
	return (this->_type);
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void		Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
