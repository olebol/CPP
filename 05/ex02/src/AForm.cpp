/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2024/01/10 21:13:22 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

AForm::AForm(void)
	:	_name("Default AForm"), _requiredGradeSign(150), _requiredGradeExec(150), _signed(false)
{
	std::cout << GREEN << "AForm: Default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string &name, const int gradeSign, const int gradeExec)
	:	_name(name), _requiredGradeSign(gradeSign), _requiredGradeExec(gradeExec), _signed(false)
{
	std::cout << GREEN << "AForm: Parametric constructor called" << RESET << std::endl;

	try
	{
		checkGrade(gradeSign);
		checkGrade(gradeExec);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _requiredGradeSign(copy._requiredGradeSign), _requiredGradeExec(copy._requiredGradeExec), _signed(copy._signed)
{
	std::cout << GREEN << "AForm: Copy constructor called" << RESET << std::endl;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	std::cout << GREEN << "AForm: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_signed = rhs._signed;
	}

	return (*this);
}

// ************************************************************************** //
//                                Destructors                                 //
// ************************************************************************** //

AForm::~AForm()
{
	std::cout << RED << "AForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Operator overloads                           //
// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const AForm &rhs)
{
	o << "AForm name: " << rhs.getName() << std::endl;
	o << "AForm required grade to sign: " << rhs.getRequiredGradeSign() << std::endl;
	o << "AForm required grade to execute: " << rhs.getRequiredGradeExec() << std::endl;
	o << "AForm signed: " << rhs.getSigned() << std::endl;
	o << std::endl;
	
	return (o);
}

// ************************************************************************** //
//                             Exceptions classes                             //
// ************************************************************************** //

const char		*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char		*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// ************************************************************************** //
//                             Getters - Setters                              //
// ************************************************************************** //

std::string		AForm::getName(void) const
{
	return (this->_name);
}

int				AForm::getRequiredGradeSign(void) const
{
	return (this->_requiredGradeSign);
}

int				AForm::getRequiredGradeExec(void) const
{
	return (this->_requiredGradeExec);
}

bool			AForm::getSigned(void) const
{
	return (this->_signed);
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void			AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requiredGradeSign)
		throw (AForm::GradeTooLowException());
	else
		this->_signed = true;
}

// ************************************************************************** //
//                               Helper functions                             //
// ************************************************************************** //

void		AForm::checkGrade(const int grade) const
{
	if (grade < 1)
		throw (AForm::GradeTooHighException());
	else if (grade > 150)
		throw (AForm::GradeTooLowException());
}
