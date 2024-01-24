/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 15:03:02 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

#include <iostream>
#include <exception>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(void)
{
	// Test default behaviour
	try
	{
		Bureaucrat					jim("Jim", 150);
		Bureaucrat					bob("Bob", 75);
		ShrubberyCreationForm		form("trees");

		std::cout << form << std::endl;

		// Too low grade to sign or execute
		jim.signForm(form);
		jim.executeForm(form);

		// Not signed
		bob.executeForm(form);

		// Sign and execute
		bob.signForm(form);
		bob.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat					bob("Bob", 75);
		Bureaucrat					jeremy("Jeremy", 40);
		RobotomyRequestForm			form("robot");

		std::cout << form << std::endl;

		// Too low grade to sign or execute
		bob.signForm(form);
		bob.executeForm(form);

		// Not signed
		jeremy.executeForm(form);
		
		// Sign and execute
		jeremy.signForm(form);
		jeremy.executeForm(form);

		// Execute a few times to see randomized
		for (int i = 0; i < 20; i++)
			jeremy.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// Test GradeTooHighException
	try
	{
		Bureaucrat		bob("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// Test GradeTooLowException
	try
	{
		Bureaucrat		bob("Bob", 151);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
