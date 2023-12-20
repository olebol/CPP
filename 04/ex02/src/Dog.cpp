/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:39:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Dog::Dog(void)
	:	AbstractAnimal("Dog")
{
	std::cout << GREEN << "Dog: Default constructor called" << RESET << std::endl;

	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << GREEN << "Dog: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << GREEN << "Dog: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;

		AbstractAnimal::operator=(rhs);

		this->_brain = new Brain(*rhs._brain);
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

Dog::~Dog()
{
	std::cout << RED << "Dog: Destructor called" << RESET << std::endl;

	delete (this->_brain);
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void		Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

void	Dog::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

const std::string	&Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}


