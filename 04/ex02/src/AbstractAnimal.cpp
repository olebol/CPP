/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:45:25 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 20:28:58 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AbstractAnimal.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

AbstractAnimal::AbstractAnimal(void)
	:	_type("AbstractAnimal")
{
	std::cout << GREEN << "AbstractAnimal: Default constructor called" << RESET << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &copy)
{
	std::cout << GREEN << "AbstractAnimal: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

AbstractAnimal	&AbstractAnimal::operator=(const AbstractAnimal &rhs)
{
	std::cout << GREEN << "AbstractAnimal: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return (*this);
}

// ************************************************************************** //
//                           Protected Constructors                           //
// ************************************************************************** //

AbstractAnimal::AbstractAnimal(const std::string &type)
	:	_type(type)
{
	std::cout << GREEN << "AbstractAnimal: Parameterized constructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

AbstractAnimal::~AbstractAnimal()
{
	std::cout << RED << "AbstractAnimal: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                 Getters                                    //
// ************************************************************************** //

const std::string		&AbstractAnimal::getType(void) const
{
	return (this->_type);
}
