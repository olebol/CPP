/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:35:39 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 20:35:45 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Span::Span(void)
{
	std::cout << GREEN << "Span: Default constructor called" << RESET << std::endl;
}

Span::Span(const Span &rhs)
{
	std::cout << GREEN << "Span: Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
	std::cout << GREEN << "Span: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
	}

	return (*this);
}

Span::~Span()
{
	std::cout << RED << "Span: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


