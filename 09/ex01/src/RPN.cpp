/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:26:23 by opelser           #+#    #+#             */
/*   Updated: 2024/02/06 15:49:50 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <iostream>

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

RPN::RPN(void)
	:	_stack()
{
	std::cout << GREEN << "RPN: Default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &rhs)
{
	std::cout << GREEN << "RPN: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

RPN &
RPN::operator=(const RPN &rhs)
{
	std::cout << GREEN << "RPN: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
		this->_stack = rhs._stack;
	}

	return (*this);
}

RPN::~RPN(void)
{
	std::cout << RED << "RPN: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void
RPN::addValueToStack(int toAdd)
{
	this->_stack.push(toAdd);
}

void
RPN::processInput(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		// Skip spaces
		if (input[i] == ' ')
			continue;
		
		// Check if character is a digit or an operator
		if (std::isdigit(input[i]))
		{
			if (std::isdigit(input[i + 1]))
				throw (RPN::InvalidValueException());
			else
				this->addValueToStack(input[i] - '0');
		}
		else
			this->performOperation(input[i]);
	}

	if (this->_stack.size() != 1)
		throw (RPN::CalculationNotPossible());
	
	std::cout << "Result: " << this->_stack.top() << std::endl;

	this->_stack.pop();
}

void
RPN::performOperation(char operatorChar)
{
	if (this->_stack.empty())
		throw (RPN::EmptyStackException());
	if (this->_stack.size() < 2)
		throw (RPN::NotEnoughValuesException());

	// Get top value and remove it from stack
	int		topValue = this->_stack.top();
	this->_stack.pop();

	//	Perform operation on top value
	switch (operatorChar)
	{
		case ('+'):
			this->_stack.top() += topValue;
			break;

		case ('-'):
			this->_stack.top() -= topValue;
			break;

		case ('*'):
			this->_stack.top() *= topValue;
			break;

		case ('/'):
			this->_stack.top() /= topValue;
			break;

		default:
			throw (RPN::InvalidOperationException());
			break;
	}
}
