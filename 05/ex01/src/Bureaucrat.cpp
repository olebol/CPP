/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:39:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Bureaucrat::Bureaucrat(void)
	:	_name("Default"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat: Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
	:	_name(name)
{
	std::cout << GREEN << "Bureaucrat: Parametric constructor called" << RESET << std::endl;

	try
	{
		this->setGrade(grade);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << GREEN << "Bureaucrat: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << GREEN << "Bureaucrat: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}

	return (*this);
}

// ************************************************************************** //
//                                Destructors                                 //
// ************************************************************************** //

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                               Operator overloads                           //
// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}

// ************************************************************************** //
//                             Exceptions classes                             //
// ************************************************************************** //

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// ************************************************************************** //
//                             Getters - Setters                              //
// ************************************************************************** //

std::string		Bureaucrat::getName(void) const
{
	return (this->_name);
}

int				Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void			Bureaucrat::setGrade(const int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void		Bureaucrat::promote(void)
{
	try
	{
		this->setGrade(this->getGrade() - 1);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void		Bureaucrat::demote(void)
{
	try
	{
		this->setGrade(this->getGrade() + 1);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void		Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}
