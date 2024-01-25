/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:28:02 by opelser           #+#    #+#             */
/*   Updated: 2024/01/25 18:28:03 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

#include <iostream>

#define GREEN "33[32m"
#define RED "33[31m"
#define RESET "33[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

ScalarConverter::ScalarConverter(void)
{
	std::cout << GREEN << "ScalarConverter: Default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	std::cout << GREEN << "ScalarConverter: Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	std::cout << GREEN << "ScalarConverter: Assignment operator called" << RESET << std::endl;
	
	if (this != &rhs)
	{
		// Perform deep copy
	}

	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


