/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 22:40:09 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

WrongCat::WrongCat(void)
	:	WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat: Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << GREEN << "WrongCat: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << GREEN << "WrongCat: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
