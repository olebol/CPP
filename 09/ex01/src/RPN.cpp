/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:26:23 by opelser           #+#    #+#             */
/*   Updated: 2024/02/14 15:19:56 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

#include <iostream>

static void
performOperation(std::stack<int> &stack, char operatorChar)
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
			if (topValue == 0)
				throw (RPN::DivideByZeroException());
			stack.top() /= topValue;
			break;

		default:
			throw (RPN::InvalidOperationException());
			break;
	}
}

static void
handleCurrentPart(std::stack<int> &stack, std::string &input)
{
	if (input.empty() || input.size() > 2)
		throw (RPN::InvalidValueException());

	else if (input.size() == 2)
	{
		if (input[0] == '-' && std::isdigit(input[1]))
			stack.push(std::stoi(input));
		else
			throw (RPN::InvalidValueException());
	}

	else if (input.size() == 1)
	{
		if (std::isdigit(input[0]))
			stack.push(input[0] - '0');
		else
			performOperation(stack, input[0]);
	}
}

void
RPN::calculate(std::string &input)
{
	std::stack<int>		stack;

	for (size_t i = 0; i < input.size(); i++)
	{
		// Get current part of input
		if (input[i] == ' ')
			continue;

		std::string		currentPart = input.substr(i, input.find(' ', i) - i);

		i += currentPart.size();

		try
		{
			handleCurrentPart(stack, currentPart);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "\"" << currentPart << "\": " << e.what() << RESET << std::endl;
			throw (RPN::CalculationNotPossible());
		}
	}

	if (stack.size() != 1)
		throw (RPN::CalculationNotPossible());

	std::cout << "Result: " << stack.top() << std::endl;

	stack.pop();
}
