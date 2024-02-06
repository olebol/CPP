/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:26:23 by opelser           #+#    #+#             */
/*   Updated: 2024/02/06 16:46:40 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <iostream>

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

RPN::RPN(void)
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

// Does not work with minus sign, should it?
void
RPN::calculate(std::string &input)
{
	std::stack<int>		stack;

	for (size_t i = 0; i < input.size(); i++)
	{
		// Skip spaces
		if (input[i] == ' ')
			continue;

		// Check if it's valid input
		if (input[i + 1] != ' ' && input[i + 1] != '\0')
			throw (RPN::InvalidValueException());

		// Check if character is a digit or an operator
		else if (std::isdigit(input[i]))
			stack.push(input[i] - '0');

		else
			RPN::performOperation(stack, input[i]);
	}

	if (stack.size() != 1)
		throw (RPN::CalculationNotPossible());
	
	std::cout << "Result: " << stack.top() << std::endl;

	stack.pop();
}

void
RPN::performOperation(std::stack<int> &stack, char operatorChar)
{
	if (stack.empty())
		throw (RPN::EmptyStackException());
	if (stack.size() < 2)
		throw (RPN::NotEnoughValuesException());

	// Get top value and remove it from stack
	int		topValue = stack.top();
	stack.pop();

	//	Perform operation on top value
	switch (operatorChar)
	{
		case ('+'):
			stack.top() += topValue;
			break;

		case ('-'):
			stack.top() -= topValue;
			break;

		case ('*'):
			stack.top() *= topValue;
			break;

		case ('/'):
			stack.top() /= topValue;
			break;

		default:
			throw (RPN::InvalidOperationException());
			break;
	}
}
