/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:02:49 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 21:59:20 by opelser          ###   ########.fr       */
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
	:	std::stack<T, Container>()
{
	std::cout << GREEN << "MutantStack<T, Container>: Default constructor called" << RESET << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &rhs)
	:	std::stack<T, Container>(rhs)
{
	std::cout << GREEN << "MutantStack: Copy constructor called" << RESET << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(const MutantStack &rhs)
{
	std::cout << GREEN << "MutantStack: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// Perform deep copy

		std::stack<T, Container>::operator=(rhs);
	}

	return (*this);
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << RED << "MutantStack: Destructor called" << RESET << std::endl;
}

# endif
