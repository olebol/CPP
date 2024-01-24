/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:19 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 19:14:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <iostream>
#include <map>

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

static AForm	*createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm	*form = NULL;

	std::map<std::string, AForm *(*)(const std::string &target)> formMap;
	
	formMap["shrubbery creation"] = &createShrubberyCreationForm;
	formMap["robotomy request"] = &createRobotomyRequestForm;
	formMap["presidential pardon"] = &createPresidentialPardonForm;

	if (formMap.find(formName) == formMap.end())
	{
		std::cout << RED << "Intern: Form name not found" << RESET << std::endl;
		return (NULL);
	}

	form = formMap[formName](target);
	std::cout << "Intern creates " << form->getName() << std::endl;

	return (form);
}
