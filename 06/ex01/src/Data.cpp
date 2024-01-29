/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:15:16 by opelser           #+#    #+#             */
/*   Updated: 2024/01/29 17:27:37 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Data::Data(void)
	:	_name("default"), _age(0)
{
	std::cout << GREEN << "Data: Default constructor called" << RESET << std::endl;
}

Data::Data(const std::string &name, int age)
	:	_name(name), _age(age)
{
	std::cout << GREEN << "Data: Parameterized constructor called" << RESET << std::endl;
}

Data::Data(const Data &rhs)
	:	_name(rhs._name), _age(rhs._age)
{
	std::cout << GREEN << "Data: Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Data &Data::operator=(const Data &rhs)
{
	std::cout << GREEN << "Data: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
		_name = rhs._name;
		_age = rhs._age;
	}

	return (*this);
}

Data::~Data()
{
	std::cout << RED << "Data: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                             Getters - Setters                              //
// ************************************************************************** //

std::string		Data::getName(void) const
{
	return (_name);
}

int				Data::getAge(void) const
{
	return (_age);
}

// ************************************************************************** //
//	                             Print Overload                               //
// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const Data &rhs)
{
	o << "Data: " << rhs.getName() << " " << rhs.getAge();
	return (o);
}
