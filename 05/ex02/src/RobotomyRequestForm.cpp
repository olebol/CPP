/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 13:57:19 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("Robotomy Request Form", 72, 45), _target("Default target")
{
	std::cout << GREEN << "RobotomyRequestForm: Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:	AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm: Parametric constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: 	AForm(copy), _target(copy._target)
{
	std::cout << GREEN << "RobotomyRequestForm: Copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << GREEN << "RobotomyRequestForm: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}

	return (*this);
}

// ************************************************************************** //
//                                Destructors                                 //
// ************************************************************************** //

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //


void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->AForm::execute(executor);

	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}
