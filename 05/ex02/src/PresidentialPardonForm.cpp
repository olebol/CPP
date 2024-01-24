/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:24:08 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 15:45:11 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("Presidential Pardon Form", 25, 5), _target("Default target")
{
	std::cout << GREEN << "PresidentialPardonForm: Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:	AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm: Parametric constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: 	AForm(copy), _target(copy._target)
{
	std::cout << GREEN << "PresidentialPardonForm: Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << GREEN << "PresidentialPardonForm: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}

	return (*this);
}

// ************************************************************************** //
//                                Destructors                                 //
// ************************************************************************** //

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //


void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->AForm::execute(executor);

	std::cout << this->_target << " has been pardoned by the great President of the Galaxy, Zaphod Beeblebrox." << std::endl;
}
