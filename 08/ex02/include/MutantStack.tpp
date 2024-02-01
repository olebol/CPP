/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:02:49 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 20:46:51 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <string>

# include "../include/MutantStack.hpp"

# include <iostream>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(void)
{
	std::cout << GREEN << "MutantStack<T, Container>: Default constructor called" << RESET << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &rhs)
{
	std::cout << GREEN << "MutantStack: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

template <typename T, class Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(const MutantStack &rhs)
{
	std::cout << GREEN << "MutantStack: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy
		c = rhs.c;
	}

	return (*this);
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << RED << "MutantStack: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                              Element Access                                //
// ************************************************************************** //

template <typename T, class Container>
T	&MutantStack<T, Container>::top(void)
{
	return (this->c.back());
}

// ************************************************************************** //
//                                 Capacity                                   //
// ************************************************************************** //

template <typename T, class Container>
bool	MutantStack<T, Container>::empty(void) const
{
	return (this->c.empty());
}

template <typename T, class Container>
size_t	MutantStack<T, Container>::size() const
{
	return (this->c.size());
}

// ************************************************************************** //
//                                 Modifiers                                  //
// ************************************************************************** //

template <typename T, class Container>
void	MutantStack<T, Container>::push(const T &val)
{
	this->c.push_back(val);
}

template <typename T, class Container>
void	MutantStack<T, Container>::pop(void)
{
	this->c.pop_back();
}

# endif
