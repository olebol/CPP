/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:46 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:39:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Brain::Brain(void)
{
	std::cout << GREEN << "Brain: Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << GREEN << "Brain: Copy constructor called" << RESET << std::endl;

	*this = copy;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	std::cout << GREEN << "Brain: Copy assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->setIdea(i, rhs.getIdea(i));
	}

	return (*this);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //

Brain::~Brain()
{
	std::cout << RED << "Brain: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                   Setters                                  //
// ************************************************************************** //

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "setIdea: index out of range" << std::endl;
		return ;
	}

	this->_ideas[index] = idea;
}

// ************************************************************************** //
//                                   Getters                                  //
// ************************************************************************** //

const std::string	&Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cout << "getIdea: index out of range" << std::endl;
		return (this->_ideas[0]);
	}
	return (this->_ideas[index]);
}

