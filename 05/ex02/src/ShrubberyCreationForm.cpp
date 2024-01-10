/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2024/01/10 21:23:38 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("Shrubbery Creation Form", 145, 137), _target("Default target")
{
	std::cout << GREEN << "ShrubberyCreationForm: Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:	AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm: Parametric constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: 	AForm(copy), _target(copy._target)
{
	std::cout << GREEN << "ShrubberyCreationForm: Copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << GREEN << "ShrubberyCreationForm: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}

	return (*this);
}

// ************************************************************************** //
//                                Destructors                                 //
// ************************************************************************** //

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void	createTrees(std::string const &target)
{
	std::string		filename = target + "_shrubbery";
	

	
	std::cout << "ASCII trees created" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (executor.getGrade() > this->getRequiredGradeExec())
			throw (AForm::GradeTooLowException());
		else
			createTrees(this->_target);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
