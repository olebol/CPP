/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2024/01/10 21:43:40 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#define TREES "\
               ,@@@@@@@, \n\
       ,,,.   ,@@@@@@/@@,  .oo8888o. \n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o \n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' \n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' \n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' \n\
   `&%\\ ` /%&'    |.|        \\ '|8' \n\
       |o|        | |         | | \n\
       |.|        | |         | | \n\
     \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_// \n"



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
	std::ofstream	outputFile(filename.c_str());

	if (!outputFile || !outputFile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}

	outputFile << TREES;

	outputFile.close();
	
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
