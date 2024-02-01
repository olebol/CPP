/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:35:39 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 18:40:04 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

#include <iostream>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Span::Span(void)
	:	_vec(0)
{
	std::cout << GREEN << "Span: Default constructor called" << RESET << std::endl;
}

Span::Span(const unsigned int n)
{
	std::cout << GREEN << "Span: Parametric constructor called" << RESET << std::endl;

	_vec.reserve(n);
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
		_vec = rhs._vec;
	}

	return (*this);
}

Span::~Span()
{
	std::cout << RED << "Span: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                             Exceptions classes                             //

const char		*Span::FullArrayException::what() const noexcept
{
	return ("Array is full");
}

const char		*Span::NumberNotFoundException::what() const noexcept
{
	return ("Number not found");
}

// ************************************************************************** //
//                             Getters and Setters                            //
// ************************************************************************** //

int		Span::getNumber(const unsigned int n) const
{
	if (n >= this->_vec.size())
		throw (Span::NumberNotFoundException());

	return (this->_vec[n]);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void	Span::addNumber(const int n)
{
	if (this->_vec.size() == this->_vec.capacity())
		throw (Span::FullArrayException());

	this->_vec.push_back(n);
}

void	Span::addRange(const int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		this->addNumber(rand() % 100);
}


