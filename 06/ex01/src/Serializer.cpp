/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:08:37 by opelser           #+#    #+#             */
/*   Updated: 2024/01/29 17:08:44 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Serializer::Serializer(void)
{
	std::cout << GREEN << "Serializer: Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &rhs)
{
	std::cout << GREEN << "Serializer: Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	std::cout << GREEN << "Serializer: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
	}

	return (*this);
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


