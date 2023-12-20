/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:39:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Cat::Cat(void)
	:	AbstractAnimal("Cat")
{
	std::cout << GREEN << "Cat: Default constructor called" << RESET << std::endl;

	this->_brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << GREEN << "Cat: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << GREEN << "Cat: Copy assignment operator called" << RESET << std::endl;

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

Cat::~Cat()
{
	std::cout << RED << "Cat: Destructor called" << RESET << std::endl;

	delete (this->_brain);
}

// ************************************************************************** //
//                               Member functions                             //
// ************************************************************************** //

void		Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

void	Cat::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

const std::string	&Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
