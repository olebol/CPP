/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:19 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 16:51:26 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Intern::Intern(void)
{
	std::cout << GREEN << "Intern: Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << GREEN << "Intern: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	std::cout << GREEN << "Intern: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		(void)rhs;
	}

	return (*this);
}

// ************************************************************************** //
//                                Destructors                                 //
// ************************************************************************** //

Intern::~Intern()
{
	std::cout << RED << "Intern: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm	*form = NULL;

	if (formName == "shrubbery creation")
	{
		form = new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request")
	{
		form = new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon")
	{
		form = new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << RED << "Intern cannot create form: unknown form name" << RESET << std::endl;
		return (NULL);
	}

	std::cout << "Intern creates " << form->getName() << std::endl;

	return (form);
}
