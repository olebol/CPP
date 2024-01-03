/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:39:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Form::Form(void)
	:	_name("Default Form"), _requiredGradeSign(150), _requiredGradeExec(150), _signed(false)
{
	std::cout << GREEN << "Form: Default constructor called" << RESET << std::endl;
}

Form::Form(const std::string &name, const int gradeSign, const int gradeExec)
	:	_name(name), _requiredGradeSign(gradeSign), _requiredGradeExec(gradeExec), _signed(false)
{
	std::cout << GREEN << "Form: Parametric constructor called" << RESET << std::endl;

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

Form::Form(const Form &copy)
	: _name(copy._name), _requiredGradeSign(copy._requiredGradeSign), _requiredGradeExec(copy._requiredGradeExec), _signed(copy._signed)
{
	std::cout << GREEN << "Form: Copy constructor called" << RESET << std::endl;
}

Form	&Form::operator=(const Form &rhs)
{
	std::cout << GREEN << "Form: Copy assignment operator called" << RESET << std::endl;

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

Form::~Form()
{
	std::cout << RED << "Form: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Operator overloads                           //
// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form name: " << rhs.getName() << std::endl;
	o << "Form required grade to sign: " << rhs.getRequiredGradeSign() << std::endl;
	o << "Form required grade to execute: " << rhs.getRequiredGradeExec() << std::endl;
	o << "Form signed: " << rhs.getSigned() << std::endl;
	o << std::endl;
	
	return (o);
}

// ************************************************************************** //
//                             Exceptions classes                             //
// ************************************************************************** //

const char		*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char		*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// ************************************************************************** //
//                             Getters - Setters                              //
// ************************************************************************** //

std::string		Form::getName(void) const
{
	return (this->_name);
}

int				Form::getRequiredGradeSign(void) const
{
	return (this->_requiredGradeSign);
}

int				Form::getRequiredGradeExec(void) const
{
	return (this->_requiredGradeExec);
}

bool			Form::getSigned(void) const
{
	return (this->_signed);
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void			Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requiredGradeSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

// ************************************************************************** //
//                               Helper functions                             //
// ************************************************************************** //

static void		checkGrade(const int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}
