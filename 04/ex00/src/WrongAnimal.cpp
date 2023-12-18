/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:17 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 22:40:12 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

WrongAnimal::WrongAnimal(void)
	:	_type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal: Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << GREEN << "WrongAnimal: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << GREEN << "WrongAnimal: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return (*this);
}

// ************************************************************************** //
//                           Protected Constructors                           //
// ************************************************************************** //

WrongAnimal::WrongAnimal(const std::string &type)
	:	_type(type)
{
	std::cout << GREEN << "WrongAnimal: Parameterized constructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                 Getters                                    //
// ************************************************************************** //

const std::string		&WrongAnimal::getType(void) const
{
	return (this->_type);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
