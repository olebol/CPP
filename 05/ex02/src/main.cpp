/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 15:40:30 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <iostream>
#include <exception>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void	testForm(Bureaucrat &jim, Bureaucrat &chad, AForm &form)
{
	std::cout << "\nTesting form: " << form.getName() << std::endl;
	try 
	{
		// Too low grade to sign or execute
		jim.signForm(form);
		jim.executeForm(form);

		// Not signed
		chad.executeForm(form);

		// Sign and execute
		chad.signForm(form);
		chad.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	try
	{
		Bureaucrat					jim("Jim", 150);
		Bureaucrat					chad("Chad", 1);
		// Bureaucrat					kyle("Kyle", 0);
		// Bureaucrat					brad("Brad", 151);

		ShrubberyCreationForm		shrubbery("house");
		RobotomyRequestForm			robotomy("human");
		PresidentialPardonForm		presidential("criminal");

		testForm(jim, chad, shrubbery);
		testForm(jim, chad, robotomy);
		testForm(jim, chad, presidential);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
