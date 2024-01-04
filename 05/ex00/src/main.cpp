/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2024/01/04 17:54:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#include <iostream>
#include <exception>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"


int main(void)
{
	// Test basic functionality
	try
	{
		Bureaucrat		bob("Bob", 1);

		std::cout << bob;

		bob.demote();

		std::cout << bob;

		bob.promote();
		bob.promote();

		std::cout << bob;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;

	}

	// Test with a grade that's too high
	try
	{
		Bureaucrat		alex("Alex", 0);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// Test with a grade that's too low
	try
	{
		Bureaucrat		alex("Alex", 151);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;

	}

	return (0);
}
