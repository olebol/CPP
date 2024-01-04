/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2024/01/04 18:57:35 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

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
		Bureaucrat		bob("Bob", 75);
		Form			form("Form with a high grade", 50, 50);
		Form			form2("Form with a low grade", 100, 100);
		
		std::cout << bob << std::endl;
		std::cout << form << form2 << std::endl;

		bob.signForm(form2);
		bob.signForm(form);

		std::cout << form << form2 << std::endl;
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
}
