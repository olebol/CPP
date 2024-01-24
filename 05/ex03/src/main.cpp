/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 16:51:58 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

#include <iostream>
#include <exception>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int	main(void)
{
	try
	{
		Bureaucrat		chad("Chad", 1);
		Intern			intern;
		AForm			*forms[4];

		forms[0] = intern.makeForm("shrubbery creation", "house");
		forms[1] = intern.makeForm("robotomy request", "human");
		forms[2] = intern.makeForm("presidential pardon", "criminal");
		forms[3] = intern.makeForm("unknown form", "unknown");

		for (int i = 0; i < 4; i++)
		{
			if (forms[i] != NULL)
				std::cout << *forms[i] << std::endl;
			else
				std::cout << "Form not found" << std::endl;
		}

		for (int i = 0; i < 4; i++)
		{
			if (forms[i] != NULL)
			{
				delete forms[i];
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
